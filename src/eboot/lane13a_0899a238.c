/* LBPMATCH module=EBOOT.BIN start=0x0899a238 end=0x0899a2ac symbol=FUN_0899a238 lang=c99 */
/* Clone of src/eboot/lane13a_089996a4.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bc0178;
extern void FUN_088050b8(void *), FUN_08a9e0cc(void *), FUN_0897489c(void *);
void FUN_0899a238(char *p) {
 char *q = *(char **)(p+32);
 *(void **)p = &DAT_08bc0178;
 if (q) {
  void *v = *(void **)(q+32);
  *(void **)(q+32) = 0;
  if (v) FUN_088050b8(v);
  if (*(void **)(q+32)) FUN_088050b8(*(void **)(q+32));
  FUN_08a9e0cc(q);
 }
 FUN_0897489c(p);
}
