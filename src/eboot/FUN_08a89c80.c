/* LBPMATCH module=EBOOT.BIN start=0x08a89c80 end=0x08a89d30 symbol=FUN_08a89c80 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. This unit is gcc404xs-O2 (conditional blocks laid out of line). */
struct Obj {
  void *vt;
  char pad4[0x98];
  int mode;
  char pad_a0[0x1c];
  void *p188;
  void *p192;
  char pad_c4[0x90];
  void *p340;
};
extern void *DAT_08bc9328[];
extern int FUN_08ac980c(void *p);
extern void *FUN_08914a7c(void);
extern void FUN_08913e58(void *a, void *b);
extern void *FUN_089f683c(void);
extern void FUN_089f62cc(void *a);
extern void FUN_088050b8(void *p);
extern void FUN_08a35074(struct Obj *o);

void FUN_08a89c80(struct Obj *o)
{
  o->vt = DAT_08bc9328;
  if (FUN_08ac980c(o->p340)) {
    FUN_08913e58(FUN_08914a7c(), o->p340);
  }
  if (o->mode == 1) {
    FUN_089f62cc(FUN_089f683c());
  }
  if (o->p192) FUN_088050b8(o->p192);
  if (o->p188) FUN_088050b8(o->p188);
  FUN_08a35074(o);
}
