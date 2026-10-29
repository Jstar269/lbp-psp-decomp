/* LBPMATCH module=EBOOT.BIN start=0x08884a38 end=0x08884a78 symbol=FUN_08884a38 lang=c99 */
/* Clone of src/eboot/f08884494_08884494.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb0b70; extern void *DAT_08bedc2c; extern void FUN_08884944(void *,int), FUN_0888f6a8(void *);
void FUN_08884a38(void **p) { DAT_08bedc2c=p; FUN_08884944(p,0); p[0]=&DAT_08bb0b70; FUN_0888f6a8(p+11); }
