/* LBPMATCH module=EBOOT.BIN start=0x0891c448 end=0x0891c490 symbol=FUN_0891c448 lang=c99 */
/* Clone of src/eboot/destroy_0891c310.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb68f0; extern void FUN_08a9df6c(void *);
void FUN_0891c448(void **p) {
 p[0]=&DAT_08bb68f0;
 if (p[1]) { FUN_08a9df6c(p[1]); p[1]=0; }
 p[2]=0;
}
