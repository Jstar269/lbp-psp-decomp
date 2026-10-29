/* LBPMATCH module=EBOOT.BIN start=0x0899e684 end=0x0899e6bc symbol=FUN_0899e684 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp15a, Codex GPT-6): float fields and offset; exact match verified; names and types await human review. */
extern char *DAT_08be85fc;
extern void FUN_0896c9e8(void *);
void FUN_0899e684(char *p) {
 char *g=*(char **)(DAT_08be85fc+688);
 char *v=*(char **)(*(char **)(g+4)+8);
 char *q=p+164;
 q[8]=1; *(float *)(q+12)=*(float *)(q+20); *(float *)(q+16)=*(float *)(v+16); *(int *)(q+4)=0;
 FUN_0896c9e8(p);
}


// 12 words differ at Os; O2 differs by 13; float and base scheduling unresolved.
// near miss from lane lbp15a (unreviewed)
