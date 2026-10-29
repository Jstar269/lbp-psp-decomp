/* LBPMATCH module=EBOOT.BIN start=0x089f73ec end=0x089f7430 symbol=FUN_089f73ec lang=c99 */
/* Clone of src/eboot/dtor_release_base_08993b4c.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void *vt;
  char pad[32];
  void *res;
};
extern void *DAT_08bc2ad8[];
extern void FUN_088050b8(void *p);
extern void FUN_0899e45c(void *p);
void FUN_089f73ec(struct Obj *self)
{
  self->vt = DAT_08bc2ad8;
  if (self->res) FUN_088050b8(self->res);
  FUN_0899e45c(self);
}
