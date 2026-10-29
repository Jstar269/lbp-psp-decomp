/* LBPMATCH module=EBOOT.BIN start=0x089f5264 end=0x089f52bc symbol=FUN_089f5264 lang=c99 */
/* Clone of src/eboot/cleanup_089914dc.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bc2ac0;
extern void FUN_088050b8(void *);
extern void FUN_0899e45c(void *);
void FUN_089f5264(void **p) {
 p[0] = &DAT_08bc2ac0;
 if (p[11]) FUN_088050b8(p[11]);
 if (p[10]) FUN_088050b8(p[10]);
 FUN_0899e45c(p);
}
