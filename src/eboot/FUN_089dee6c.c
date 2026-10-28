/* LBPMATCH module=EBOOT.BIN start=0x089dee6c end=0x089dee88 symbol=FUN_089dee6c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Node {
  char pad_00[8];
  int value;   /* +8 */
};

struct Obj {
  char pad_00[0x18];
  char unk_18[8];        /* +0x18: embedded sentinel */
  struct Node *unk_20;   /* +0x20: equals the sentinel's address when there is nothing to return */
};

int FUN_089dee6c(struct Obj *self)
{
  int value;

  value = 0;
  if (self->unk_20 != (struct Node *)self->unk_18) {
    value = self->unk_20->value;
  }
  return value;
}
