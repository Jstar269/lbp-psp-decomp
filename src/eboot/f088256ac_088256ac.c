/* LBPMATCH module=EBOOT.BIN start=0x088256ac end=0x0882570c symbol=FUN_088256ac lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bad844;
extern void *FUN_08a9e824(int);
extern int FUN_08ba0984(const char *,const char *,...);
void FUN_088256ac(void *unused, const char *text, void **out) { float *p=FUN_08a9e824(12); FUN_08ba0984(text,&DAT_08bad844,p,p+1,p+2); *out=p; }
