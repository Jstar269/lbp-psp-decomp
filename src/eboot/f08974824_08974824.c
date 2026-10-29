/* LBPMATCH module=EBOOT.BIN start=0x08974824 end=0x08974860 symbol=FUN_08974824 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bbd200;
extern void FUN_08974380(void *, void *);
void FUN_08974824(int *p, int x, void *q) {
 p[3]=x; p[0]=(int)&DAT_08bbd200; p[1]=0; p[2]=0; p[4]=0; p[5]=0; p[6]=0;
 if(q) FUN_08974380(p,q);
}

