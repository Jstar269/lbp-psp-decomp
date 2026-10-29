/* LBPMATCH module=EBOOT.BIN start=0x08b8ab50 end=0x08b8ab84 symbol=FUN_08b8ab50 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g3) corrected by hand (lane lbp15a, Codex GPT-6): restored third argument; exact match verified; names and types await human review. */
extern void *FUN_08b8aa40(char *, char *, int);
void FUN_08b8ab50(void **out, char *p, int n, int x) { *out=FUN_08b8aa40(p,n+p,x); }

// One word differs: reversed addu operands; reversing C operands did not change it.
// near miss from lane lbp15a (unreviewed)
