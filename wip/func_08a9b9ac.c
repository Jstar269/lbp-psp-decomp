/* LBPMATCH module=EBOOT.BIN start=0x08a9b9ac end=0x08a9ba00 symbol=FUN_08a9b9ac lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); names and types await human review. */
extern void *FUN_08a9e838(unsigned); extern void FUN_08b9e8cc(void *,void *,int);
void *FUN_08a9b9ac(void *unused,unsigned n,char *a,char *b){ void *p=FUN_08a9e838(n); FUN_08b9e8cc(p,a,b-a); return p; }
// Instruction scheduling differs despite matching size.
// near miss from lane lbp14c (unreviewed)
