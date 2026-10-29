/* LBPMATCH module=EBOOT.BIN start=0x0882586c end=0x088258d0 symbol=FUN_0882586c lang=c99 */
/* Clone of src/eboot/function_088254c8.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bad840; extern void *FUN_08a9e824(int); extern void FUN_08ba0984(void *,void *,void *,void *,void *,void *);
void FUN_0882586c(void *unused,void *a,void **out) { char *p=FUN_08a9e824(16); FUN_08ba0984(a,&DAT_08bad840,p,p+4,p+8,p+12); *out=p; }
