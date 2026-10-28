/* LBPMATCH module=EBOOT.BIN start=0x089745b8 end=0x08974640 symbol=FUN_089745b8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int *DAT_08be85f8;
extern void FUN_08967568();
extern void FUN_08968924();

/* Object with a virtual table; flag bit 2 of the word at +4 asks for a callback through slot 8. */
struct Callback {
  void (**vtable)();
  unsigned int flags;
};

struct Owner {
  char unk_00[0x10];
  int unk_10;
  struct Callback *callback;
};

void FUN_089745b8(struct Owner *self)
{
  struct Callback *callback;

  callback = self->callback;
  if ((callback != (struct Callback *)0x0) && ((callback->flags & 4U) != 0)) {
    (*callback->vtable[8])(callback);
  }
  if (DAT_08be85f8 != (int *)0x0) {
    if (self->unk_10 != 0) {
      FUN_08968924(DAT_08be85f8,self->unk_10);
    }
    FUN_08967568(DAT_08be85f8);
    return;
  }
  return;
}
