/* LBPMATCH module=EBOOT.BIN start=0x089914dc end=0x08991534 symbol=FUN_089914dc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bbfbc8;
extern void FUN_088050b8(void *);
extern void FUN_0897489c(void *);
void FUN_089914dc(void **p) {
 p[0] = &DAT_08bbfbc8;
 if (p[11]) FUN_088050b8(p[11]);
 if (p[10]) FUN_088050b8(p[10]);
 FUN_0897489c(p);
}
