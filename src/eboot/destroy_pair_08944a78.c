/* LBPMATCH module=EBOOT.BIN start=0x08944a78 end=0x08944ac8 symbol=FUN_08944a78 lang=c99 */
/* Clone of src/eboot/destroy_pair_08923590.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb7468,DAT_08bb74d0,DAT_08bb74e0; extern void FUN_0894a260(void *);
void FUN_08944a78(void **p) { p[0]=&DAT_08bb7468; p[2]=&DAT_08bb74d0; FUN_0894a260(p+2); p[0]=&DAT_08bb74e0; FUN_0894a260(p); }

