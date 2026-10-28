"""Find unmatched C++ static-init functions of the ref-counted-holder shape and write sources for them
(template: src/eboot/static_init_08804948.cpp / static_init_089f8e28.cpp). Output dir argv[1]."""
import sys, struct, pathlib, subprocess, collections
sys.path.insert(0, "tools")
import lbpmatch as M
out = pathlib.Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
data, seg = M.module_bytes({}, "EBOOT.BIN")
def words(a, b):
    o = seg["file_offset"] + a - seg["start"]
    return struct.unpack_from(f"<{(b-a)//4}I", data, o)
covered = {M.parse_header(p)["start"] for p in (M.ROOT/"src").rglob("*") if p.suffix in (".c", ".cpp")}
funcs = [tuple(int(x, 16) for x in l.split()[:2]) for l in open("data/functions-EBOOT.BIN.txt") if l.strip()]
s16 = lambda x: x - 0x10000 if x & 0x8000 else x
stats = collections.Counter(); made = []
for a, b in funcs:
    if a in covered or b - a < 64: continue
    w = words(a, b)
    if w[0] != 0x27bdfff0 or w[1] != 0x24020001 or w[2] != 0xafbf0000: continue
    op = w[3] >> 16
    if op not in (0x1482, 0x1082): stats["other-branch"] += 1; continue
    cc = "gcc404xs-Os" if op == 0x1482 else "gcc404xs-O2"
    # lui tracking per register
    lui = {}; counts = []; datas = []; fstores = []; gstores = {}; rodatas = []
    last_li = {}
    cidx = []; didx = {}
    for i, x in enumerate(w):
        opc = x >> 26; rs = (x >> 21) & 31; rt = (x >> 16) & 31; imm = x & 0xffff
        dst = (x >> 11) & 31 if opc == 0 else rt if (0x08 <= opc <= 0x0f or 0x20 <= opc <= 0x25) else None
        if dst is not None:
            last_li.pop(dst, None)
            if opc != 0x0f: lui.pop(dst, None)
        if opc == 0x0f: lui[rt] = imm << 16; continue
        if opc == 0x09 and rs == 0:  # li rt,imm (addiu rt,zero,imm)
            last_li[rt] = s16(imm); continue
        if opc == 0x0d and rs == 0: last_li[rt] = imm; continue
        if opc == 0x09 and rs == 3 and rt == 2 and rs in lui:  # addiu v0, v1(lui), imm  -> data address
            datas.append((lui[rs] + s16(imm)) & 0xffffffff); didx[i] = datas[-1]; continue
        if opc == 0x23 and rs in lui:  # lw
            ad = (lui[rs] + s16(imm)) & 0xffffffff
            nx = w[i + 2] if i + 2 < len(w) else 0
            if (nx >> 26) == 0x09 and ((nx >> 21) & 31) == rt and (nx & 0xffff) == 1: counts.append(ad); cidx.append((i, ad))
            continue
        if opc == 0x39 and rs in lui: fstores.append((lui[rs] + s16(imm)) & 0xffffffff); continue
        if opc == 0x31 and rs in lui: rodatas.append((lui[rs] + s16(imm)) & 0xffffffff); continue
        if opc == 0x2b and rs in lui and rt in last_li:
            gstores[(lui[rs] + s16(imm)) & 0xffffffff] = last_li[rt]
    if len(fstores) > 1 or len(rodatas) != len(fstores): stats["floats"] += 1; continue
    rodata = rodatas[0] if rodatas else None
    vals = {}
    for k in fstores:
        o = seg["file_offset"] + rodata - seg["start"]
        vals[k] = ("float", "%.9gf" % struct.unpack_from("<f", data, o)[0])
    holder = set(counts) | {c + 4 for c in counts} | {d + k for d in datas for k in range(0, 0x18, 4)}
    for k, v in gstores.items():
        if k not in holder: vals[k] = ("int", str(v))
    g = min(vals) if vals else 0
    # GCC lays the globals out in reverse definition order (the first defined gets the highest address), and the
    # dynamic initialisation follows definition order: derive the definition order from the retail addresses
    defs = [(ad,) + vals[ad] for ad in sorted(vals, reverse=True)]
    if vals and max(vals) - g != 4 * (len(vals) - 1): stats["globals-gaps"] += 1; continue
    variants = {"a": defs}
    # pair each holder's count with its data block: follow the first conditional branch after the count load
    # (bne: the clears follow; beq: the clears are out of line at the branch target)
    seen, dseen = [], []
    ok = True
    for i, c in cidx:
        if c in seen: continue
        j = next((k for k in range(i + 1, len(w)) if (w[k] >> 26) in (4, 5)), None)
        if j is None: ok = False; break
        start = j + 1 + s16(w[j] & 0xffff) if (w[j] >> 26) == 4 else j + 1
        d = next((didx[k] for k in sorted(didx) if k >= start), None)
        if d is None: ok = False; break
        seen.append(c); dseen.append(d)
    if not ok or not seen or len(set(dseen)) != len(dseen): stats["pairing"] += 1; continue
    for vk, dl in variants.items():
        name = out / vk / f"static_init_{a:08x}.cpp"; name.parent.mkdir(exist_ok=True)
        env = dict(__import__("os").environ, SI_GLOBALS=",".join(f"{ad:08x}:{ty}:{v}" for ad, ty, v in dl))
        if rodata is not None: env["SI_RODATA"] = f"0x{rodata:08x}"
        args = [sys.executable, "wip/t/mksi.py", f"0x{a:08x}", f"0x{b:08x}", f"0x{g:08x}", cc, str(name)] +                [f"{c:08x}:{d:08x}" for c, d in zip(seen, dseen)]
        subprocess.run(args, check=True, env=env)
    made.append(a); stats[cc] += 1
print(dict(stats), len(made))
