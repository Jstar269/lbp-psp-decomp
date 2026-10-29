/* LBPMATCH module=EBOOT.BIN start=0x08993b90 end=0x08993bdc symbol=FUN_08993b90 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void *vt;
  char pad[32];
  void *res;
};
extern void *DAT_08bc0490[];
extern void FUN_088050b8(void *p);
extern void FUN_0899e45c(void *p);
extern void FUN_08a9e0cc(void *p);
void FUN_08993b90(struct Obj *self)
{
  self->vt = DAT_08bc0490;
  if (self->res) FUN_088050b8(self->res);
  FUN_0899e45c(self);
  FUN_08a9e0cc(self);
}
