/* LBPMATCH module=EBOOT.BIN start=0x089eaa7c end=0x089eaabc symbol=FUN_089eaa7c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { char pad[0x1b8]; int mode; };
int FUN_089eaa7c(struct Obj *o)
{
  int m = o->mode;
  if (m == 2) return 1;
  if (m <= 2) { if (m < 0) return 0; return 3; }
  if (m != 3) return 0;
  return 3;
}
