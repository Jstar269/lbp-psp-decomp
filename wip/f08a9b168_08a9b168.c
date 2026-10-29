/* LBPMATCH module=EBOOT.BIN start=0x08a9b168 end=0x08a9b1a4 symbol=FUN_08a9b168 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp15a, Codex GPT-6); exact match verified; names and types await human review. */
extern char *FUN_08a9e838(int);
void FUN_08a9b168(void *unused, int *p) { char *q=FUN_08a9e838(12); if ((unsigned)q + 8) *(int *)(q+8)=*p; }


// 10 words differ; Os and O2 fold the adjusted-pointer null check to comparison with -8.
// near miss from lane lbp15a (unreviewed)
