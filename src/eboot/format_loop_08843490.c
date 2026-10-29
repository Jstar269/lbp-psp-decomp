/* LBPMATCH module=EBOOT.BIN start=0x08843490 end=0x0884350c symbol=FUN_08843490 lang=c99 */
/* Clone of src/eboot/format_loop_08843414.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bae3fc, DAT_08bae410;
extern void FUN_08b9cef4(void *, void *), FUN_08b9ce3c(void *, void *, void *);
void FUN_08843490(char *p, void *out, int n) { int i=0; while (i++ < n) FUN_08b9cef4(&DAT_08bae3fc,out); FUN_08b9ce3c(out,&DAT_08bae410, *(char **)(p+32)+8); }

