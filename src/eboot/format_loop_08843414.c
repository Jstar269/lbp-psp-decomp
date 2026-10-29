/* LBPMATCH module=EBOOT.BIN start=0x08843414 end=0x08843490 symbol=FUN_08843414 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bae3fc, DAT_08bae404;
extern void FUN_08b9cef4(void *, void *), FUN_08b9ce3c(void *, void *, void *);
void FUN_08843414(char *p, void *out, int n) { int i=0; while (i++ < n) FUN_08b9cef4(&DAT_08bae3fc,out); FUN_08b9ce3c(out,&DAT_08bae404, *(char **)(p+32)+8); }

