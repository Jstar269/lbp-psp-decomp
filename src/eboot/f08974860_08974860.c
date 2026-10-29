/* LBPMATCH module=EBOOT.BIN start=0x08974860 end=0x0897489c symbol=FUN_08974860 lang=c99 */
/* Clone of src/eboot/f08974824_08974824.c (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp15a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bbd200;
extern void FUN_08974380(void *, void *);
void FUN_08974860(int *p, int x, void *q) {
 p[3]=x; p[0]=(int)&DAT_08bbd200; p[1]=0; p[2]=0; p[4]=0; p[5]=0; p[6]=0;
 if(q) FUN_08974380(p,q);
}

