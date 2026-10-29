/* LBPMATCH module=EBOOT.BIN start=0x0899d558 end=0x0899d59c symbol=FUN_0899d558 lang=c99 */
/* Clone of src/eboot/dtor_release_base_08993b4c.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void *vt;
  char pad[32];
  void *res;
};
extern void *DAT_08bc0490[];
extern void FUN_088050b8(void *p);
extern void FUN_0899e45c(void *p);
void FUN_0899d558(struct Obj *self)
{
  self->vt = DAT_08bc0490;
  if (self->res) FUN_088050b8(self->res);
  FUN_0899e45c(self);
}
