/* LBPMATCH module=EBOOT.BIN start=0x088b11bc end=0x088b1228 symbol=FUN_088b11bc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Unk4Pair {
  int unk_00;
  int unk_04;
};

struct Obj {
  char pad_00[0x12];
  unsigned char unk_12;
};

extern struct Unk4Pair *FUN_0889b768(void);
extern void FUN_0889ba9c(struct Unk4Pair *target, int arg1, int arg2, void (*callback)());
extern void FUN_088cef4c();

/* While the flag at +0x12 is set and the word at +4 of the object returned by FUN_0889b768 is not 3, clear the flag
   and hand that object (1, 3, FUN_088cef4c) to FUN_0889ba9c. */
void FUN_088b11bc(struct Obj *self)
{
  struct Unk4Pair *target;

  if ((self->unk_12 != 0) && (target = FUN_0889b768(), target->unk_04 != 3)) {
    self->unk_12 = 0;
    target = FUN_0889b768();
    FUN_0889ba9c(target, 1, 3, FUN_088cef4c);
    return;
  }
  return;
}
