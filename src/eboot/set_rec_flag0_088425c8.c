/* LBPMATCH module=EBOOT.BIN start=0x088425c8 end=0x08842624 symbol=FUN_088425c8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Rec { char pad[12]; unsigned char flags; };
struct Res { char pad[0xa8]; void *rec_src; };
struct Obj { char pad0[4]; unsigned char dirty; char pad1[3]; struct Res *res; };
extern struct Rec *FUN_0891d6e4(void *p);

void FUN_088425c8(struct Obj *o, unsigned char on)
{
  struct Rec *r = FUN_0891d6e4(o->res->rec_src);
  if (on) {
    r->flags &= 0xfe;
  } else {
    r->flags |= 1;
  }
  o->dirty = 1;
}
