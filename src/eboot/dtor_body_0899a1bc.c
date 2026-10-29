/* LBPMATCH module=EBOOT.BIN start=0x0899a1bc end=0x0899a238 symbol=FUN_0899a1bc lang=c99 */
/* Clone of src/eboot/dtor_body_08999628.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc0178[];
extern void FUN_088050b8(void *);
extern void FUN_08a9e0cc(void *);
extern void FUN_0897489c(void *);
struct Inner { char pad[32]; void *p; };
struct Obj { void *vt; char pad[28]; struct Inner *inner; };
void FUN_0899a1bc(struct Obj *self)
{
  struct Inner *in = self->inner;
  self->vt = DAT_08bc0178;
  if (in != 0) {
    void *p = in->p;
    in->p = 0;
    if (p != 0) FUN_088050b8(p);
    if (in->p != 0) FUN_088050b8(in->p);
    FUN_08a9e0cc(in);
  }
  FUN_0897489c(self);
  FUN_08a9e0cc(self);
}
