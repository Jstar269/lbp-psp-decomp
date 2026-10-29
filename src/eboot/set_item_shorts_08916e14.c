/* LBPMATCH module=EBOOT.BIN start=0x08916e14 end=0x08916e64 symbol=FUN_08916e14 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Item { char pad0[4]; short a; char pad1[8]; short b; char pad2[40]; };
struct Owner { char pad[16]; int count; };
struct Entry { struct Owner *owner; int pad4; struct Item *items; int pad12; };
extern struct Entry *DAT_08bef4b4;

void FUN_08916e14(int idx, short value)
{
  struct Entry *e = DAT_08bef4b4 + idx;
  int i;
  for (i = 0; i < e->owner->count; i++) {
    struct Item *it = &e->items[i];
    it->a = value;
    it->b = value;
  }
}
