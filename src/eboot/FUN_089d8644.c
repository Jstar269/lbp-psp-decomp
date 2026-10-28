/* LBPMATCH module=EBOOT.BIN start=0x089d8644 end=0x089d866c symbol=FUN_089d8644 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Node {
  char pad_00[0xc];
  short unk_0c;
  short unk_0e;
};

struct Obj {
  char pad_00[0x18];
  char sentinel[8];          /* +0x18: end marker compared against `current` */
  struct Node *current;      /* +0x20 */
  char pad_24[0x80];
  int unk_a4;                /* selects which short of the current node is returned */
};

/* Short of the current node (-1 when `current` is at the end marker). */
int FUN_089d8644(struct Obj *self)
{
  struct Node *node;
  int result;

  node = self->current;
  result = -1;
  if (node != (struct Node *)self->sentinel) {
    if (self->unk_a4 == 0) {
      result = node->unk_0e;
    }
    else {
      result = node->unk_0c;
    }
  }
  return result;
}
