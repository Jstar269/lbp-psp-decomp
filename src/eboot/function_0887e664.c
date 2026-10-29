/* LBPMATCH module=EBOOT.BIN start=0x0887e664 end=0x0887e6c8 symbol=FUN_0887e664 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb0980,DAT_08bb0828; extern void FUN_0887dc00(void *),FUN_08a9e0cc(void *),FUN_0888b898(void *);
void FUN_0887e664(void **p) { void *x=p[3]; p[0]=&DAT_08bb0980; if(x) { FUN_0887dc00(x); FUN_08a9e0cc(x); } FUN_0888b898(p+8); p[0]=&DAT_08bb0828; }
