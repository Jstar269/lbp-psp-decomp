/* LBPMATCH module=EBOOT.BIN start=0x088d7508 end=0x088d753c symbol=FUN_088d7508 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { int pad0; int kind; };
int FUN_088d7508(int unused, struct Obj *o)
{
  switch (o->kind) {
  case 2: return 2;
  case 3: return 1;
  case 4: return 3;
  }
  return 0;
}
