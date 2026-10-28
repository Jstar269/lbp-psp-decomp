/* LBPMATCH module=EBOOT.BIN start=0x088437b8 end=0x08843824 symbol=FUN_088437b8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Child {
  int (**vtable)();
  char pad_04[0x24];
  struct Child *next;
};

struct Parent {
  char pad_00[0x18];
  struct Child *first;
};

extern unsigned int FUN_08b9ce78();

/* Call vtable slot 2 of every child in the chain (next at +0x28), following each with FUN_08b9ce78(10, arg1). */
void FUN_088437b8(struct Parent *self, unsigned int *arg1, unsigned int arg2)
{
  struct Child *child;

  for (child = self->first; child != 0; child = child->next) {
    child->vtable[2](child, arg1, arg2);
    FUN_08b9ce78(10, arg1);
  }
}
