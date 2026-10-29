/* LBPMATCH module=EBOOT.BIN start=0x08962884 end=0x08962908 symbol=FUN_08962884 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { int pad; unsigned flags; } Obj;
typedef struct G { char pad[0x84]; Obj *obj; unsigned char busy; } G;
extern G *DAT_08bf03b8;
extern void FUN_0896270c(int a, Obj *o);
extern void FUN_089757c0(int id);
extern void FUN_08961c74(int a, Obj *o);
void FUN_08962884(int a)
{
  if (DAT_08bf03b8->busy == 0) {
    Obj *o = DAT_08bf03b8->obj;
    unsigned f;
    FUN_0896270c(a, o);
    f = o->flags;
    if (f & 0x800)
      FUN_089757c0(0x38);
    else if (f & 0x1000)
      FUN_089757c0(0x39);
    FUN_08961c74(a, o);
  }
}
