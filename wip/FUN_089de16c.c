/* LBPMATCH module=EBOOT.BIN start=0x089de16c end=0x089de1a8 symbol=FUN_089de16c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Slot { char pad[0x18]; int f18; };
struct Obj { char pad[0x40]; struct Slot *slots[4]; unsigned char state[4]; };
void FUN_089de16c(struct Obj *o)
{
  int i;
  if (o->slots[0] != 0) {
    for (i = 0; i < 4; i++) {
      struct Slot *s = o->slots[i];
      o->state[i] = 2;
      s->f18 = 0;
    }
  }
}
// 4 words differ (O2): register roles of the two induction pointers are swapped: retail advances the incoming a0 by 4 (slot loads, lw 64(a0)) and a copy v1 by 1 (sb 80(v1)); ours the reverse. Tried struct/index form, Ghidra pointer form, role swap (worse, store/load reorder), down-counting Os form.
// near miss from lane lbp6a (unreviewed)
