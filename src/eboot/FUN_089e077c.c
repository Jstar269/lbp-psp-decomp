/* LBPMATCH module=EBOOT.BIN start=0x089e077c end=0x089e081c symbol=FUN_089e077c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 8-byte struct return copied from a member of a packed struct (lwl/lwr). */
typedef struct Rect { unsigned short x, y, w, h; } Rect;
typedef struct Item { char pad[12]; Rect rect; } __attribute__((packed)) Item;

struct Child;
typedef struct ChildVT { char pad[0x4c]; Item *(*get)(struct Child *); } ChildVT;
typedef struct Child { const ChildVT *vt; } Child;
typedef struct Obj { char pad[0x10]; Child *child; } Obj;

Rect FUN_089e077c(Obj *self)
{
  Child *c = self->child;
  if (c)
    return c->vt->get(c)->rect;
  Rect z;
  z.x = 0; z.y = 0; z.w = 0; z.h = 0;
  return z;
}
