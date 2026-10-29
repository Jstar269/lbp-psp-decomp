/* LBPMATCH module=EBOOT.BIN start=0x08842624 end=0x08842680 symbol=FUN_08842624 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Rec { char pad[12]; unsigned char flags; };
struct Res { char pad[0xa8]; void *rec_src; };
struct Obj { char pad0[4]; unsigned char dirty; char pad1[3]; struct Res *res; };
extern struct Rec *FUN_0891d6e4(void *p);

void FUN_08842624(struct Obj *o, unsigned char on)
{
  struct Rec *r = FUN_0891d6e4(o->res->rec_src);
  if (on) {
    r->flags |= 2;
  } else {
    r->flags &= 0xfd;
  }
  o->dirty = 1;
}
