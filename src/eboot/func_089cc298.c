/* LBPMATCH module=EBOOT.BIN start=0x089cc298 end=0x089cc2ec symbol=FUN_089cc298 lang=c99 */
/* Clone of src/eboot/func_089c10e0.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bc1290; extern void FUN_08974824(void *,void *,int),FUN_08974380(void *,int),FUN_08974070(void *);
void FUN_089cc298(void **p,void *a,int b){ FUN_08974824(p,a,0); p[0]=&DAT_08bc1290; FUN_08974380(p,0); void **q=p[5]; q[7]=(void *)b; FUN_08974070(q); }
