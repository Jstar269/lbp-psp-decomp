//@category LbpDecomp
// Advisory pseudocode for lbpgen: commit decompiler-inferred parameters and return types for every
// function (as the "Decompiler Parameter ID" analyzer would), then decompile everything again so call
// sites see their callees' committed prototypes. Runs on a private copy of the candidate project;
// never on campaign evidence. Output layout matches the toolkit's DecompileAll.java.
// Optional 4th argument: a boundaries file ("<start hex> <end hex>" per line, end exclusive, from the
// campaign ledger). Before decompiling, function bodies are set to exactly those ranges (functions
// Ghidra did not create are created; overlapping ones are trimmed or removed). The project is opened
// read-only, so these edits live only in this session.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressRangeIterator;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.HighFunctionDBUtil;
import ghidra.program.model.symbol.SourceType;
import java.io.BufferedWriter;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Locale;

public class LbpCommitDecompile extends GhidraScript {
    private static String json(String value) {
        StringBuilder out = new StringBuilder("\"");
        for (int i = 0; i < value.length(); i++) {
            char c = value.charAt(i);
            switch (c) {
                case '\\': out.append("\\\\"); break;
                case '"': out.append("\\\""); break;
                case '\n': out.append("\\n"); break;
                case '\r': out.append("\\r"); break;
                case '\t': out.append("\\t"); break;
                default:
                    if (c < 0x20) out.append(String.format("\\u%04x", (int)c));
                    else out.append(c);
            }
        }
        return out.append('"').toString();
    }

    private static String sha256(String value) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256").digest(value.getBytes(StandardCharsets.UTF_8));
        StringBuilder out = new StringBuilder();
        for (byte b : digest) out.append(String.format("%02x", b & 0xff));
        return out.toString();
    }

    private static String bodyRanges(Function function) {
        StringBuilder out = new StringBuilder("[");
        AddressRangeIterator ranges = function.getBody().getAddressRanges();
        boolean first = true;
        while (ranges.hasNext()) {
            AddressRange range = ranges.next();
            if (!first) out.append(',');
            first = false;
            out.append("{\"space\":").append(json(range.getMinAddress().getAddressSpace().getName()))
                    .append(",\"start\":").append(range.getMinAddress().getOffset())
                    .append(",\"end\":").append(range.getMaxAddress().getOffset() + 1).append('}');
        }
        return out.append(']').toString();
    }

    private DecompInterface open(boolean syntaxTree) {
        DecompInterface decompiler = new DecompInterface();
        decompiler.setOptions(new DecompileOptions());
        decompiler.toggleCCode(!syntaxTree);
        decompiler.toggleSyntaxTree(syntaxTree);
        if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException("decompiler could not open program");
        return decompiler;
    }

    private void applyBoundaries(File file) throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        long created = 0, rebounded = 0, removed = 0, errors = 0;
        for (String line : Files.readAllLines(file.toPath(), StandardCharsets.UTF_8)) {
            String[] parts = line.trim().split("\\s+");
            if (parts.length < 2) continue;
            monitor.checkCancelled();
            try {
                Address start = toAddr(Long.parseLong(parts[0], 16));
                Address last = toAddr(Long.parseLong(parts[1], 16) - 1);
                AddressSet body = new AddressSet(start, last);
                List<Function> overlapping = new ArrayList<>();
                Iterator<Function> it = fm.getFunctionsOverlapping(body);
                while (it.hasNext()) overlapping.add(it.next());
                for (Function other : overlapping) {
                    if (other.getEntryPoint().equals(start)) continue;
                    AddressSetView rest = other.getBody().subtract(body);
                    if (rest.isEmpty() || body.contains(other.getEntryPoint())) {
                        fm.removeFunction(other.getEntryPoint());
                        removed++;
                    } else {
                        other.setBody(rest);
                        rebounded++;
                    }
                }
                if (getInstructionAt(start) == null) disassemble(start);
                Function function = fm.getFunctionAt(start);
                if (function == null) {
                    fm.createFunction(null, start, body, SourceType.ANALYSIS);
                    created++;
                } else if (!function.getBody().equals(body)) {
                    function.setBody(body);
                    rebounded++;
                }
            } catch (Exception e) {
                errors++;
                if (errors <= 20) println("LbpCommitDecompile: boundary " + line.trim() + ": " + e);
            }
        }
        println("LbpCommitDecompile: boundaries created=" + created + " rebounded=" + rebounded + " removed=" + removed + " errors=" + errors);
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("usage: LbpCommitDecompile.java <output-dir> [commit-passes] [timeout]");
        int passes = args.length > 1 ? Integer.parseInt(args[1]) : 1;
        int timeout = args.length > 2 ? Integer.parseInt(args[2]) : 60;
        File output = new File(args[0]).getAbsoluteFile();
        File pseudocodeDir = new File(output, "pseudocode");
        if (!pseudocodeDir.isDirectory() && !pseudocodeDir.mkdirs()) throw new IllegalStateException("cannot create output directory");
        if (args.length > 3 && !args[3].isEmpty()) applyBoundaries(new File(args[3]));

        for (int pass = 1; pass <= passes; pass++) {
            DecompInterface decompiler = open(true);
            long committed = 0, failed = 0;
            try {
                FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
                while (functions.hasNext()) {
                    monitor.checkCancelled();
                    Function function = functions.next();
                    if (function.isThunk() || function.isExternal()) continue;
                    DecompileResults result = decompiler.decompileFunction(function, timeout, monitor);
                    HighFunction high = result == null ? null : result.getHighFunction();
                    if (high == null) { failed++; continue; }
                    try {
                        HighFunctionDBUtil.commitParamsToDatabase(high, true, HighFunctionDBUtil.ReturnCommitOption.COMMIT, SourceType.ANALYSIS);
                        committed++;
                    } catch (Exception e) {
                        failed++;
                    }
                }
            } finally {
                decompiler.dispose();
            }
            println("LbpCommitDecompile: pass " + pass + " committed=" + committed + " failed=" + failed);
        }

        DecompInterface decompiler = open(false);
        long total = 0, completed = 0, failures = 0;
        try (BufferedWriter index = Files.newBufferedWriter(new File(output, "functions.jsonl").toPath(), StandardCharsets.UTF_8)) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                monitor.checkCancelled();
                Function function = functions.next();
                total++;
                String address = String.format(Locale.ROOT, "%08x", function.getEntryPoint().getOffset());
                String space = function.getEntryPoint().getAddressSpace().getName();
                String status = "failed", file = "", sha = "", failure = "";
                DecompileResults result = decompiler.decompileFunction(function, timeout, monitor);
                if (result != null && result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    String c = result.getDecompiledFunction().getC();
                    String name = space.replaceAll("[^A-Za-z0-9._-]", "_") + "-0x" + address + ".c";
                    Files.writeString(new File(pseudocodeDir, name).toPath(), c, StandardCharsets.UTF_8);
                    status = "decompiled";
                    file = "pseudocode/" + name;
                    sha = sha256(c);
                    completed++;
                } else {
                    failures++;
                    failure = result == null ? "no-result" : String.valueOf(result.getErrorMessage());
                }
                index.write("{\"address\":" + json("0x" + address) + ",\"address_space\":" + json(space) +
                        ",\"name\":" + json(function.getName()) + ",\"body_bytes\":" + function.getBody().getNumAddresses() +
                        ",\"body_ranges\":" + bodyRanges(function) + ",\"thunk\":" + function.isThunk() +
                        ",\"pseudocode_status\":" + json(status) + ",\"pseudocode_file\":" + json(file) +
                        ",\"pseudocode_sha256\":" + json(sha) + ",\"failure\":" + json(failure) + "}\n");
            }
        } finally {
            decompiler.dispose();
        }
        println("LbpCommitDecompile: exported functions=" + total + " decompiled=" + completed + " failed=" + failures);
    }
}
