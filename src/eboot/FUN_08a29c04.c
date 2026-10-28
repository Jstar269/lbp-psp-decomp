/* LBPMATCH module=EBOOT.BIN start=0x08a29c04 end=0x08a29c6c symbol=FUN_08a29c04 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Obj {
  char pad_00[0xd7c];
  void *owned[8];            /* +0xd7c..+0xd98: eight pointers released together */
};

extern int DAT_08bef194;
extern void FUN_08a9e0cc();

void FUN_08a29c04(struct Obj *self)
{
  FUN_08a9e0cc(self->owned[0]);
  FUN_08a9e0cc(self->owned[1]);
  FUN_08a9e0cc(self->owned[2]);
  FUN_08a9e0cc(self->owned[3]);
  FUN_08a9e0cc(self->owned[4]);
  FUN_08a9e0cc(self->owned[5]);
  FUN_08a9e0cc(self->owned[6]);
  FUN_08a9e0cc(self->owned[7]);
  DAT_08bef194 = 0;
}
