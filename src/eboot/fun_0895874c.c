/* LBPMATCH module=EBOOT.BIN start=0x0895874c end=0x08958770 symbol=FUN_0895874c lang=c99 */
/* Clone of src/eboot/fun_08918580.c (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py tag g13) corrected by hand (lane lbp15b, Codex GPT-6): precompute value; exact match verified; names and types await human review. */
int FUN_0895874c(int *p, int x, int *out) { int v=x+p[1]; if (p[0]==0x5441444d) *out=v; return 0; }

