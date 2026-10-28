/* LBPMATCH module=EBOOT.BIN start=0x088ece98 end=0x088ecee8 symbol=FUN_088ece98 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0xa0];
  int unk_a0;
  int unk_a4;
};

extern void FUN_088eca74(struct Obj *self, int arg1, int arg2);
extern void FUN_088ece00(struct Obj *self, int arg1);

void FUN_088ece98(struct Obj *self)
{
  FUN_088ece00(self, 0);
  FUN_088eca74(self, 0, 0xf8);
  if (self->unk_a4 != 0) {
    self->unk_a4 = 0;
  }
  if (self->unk_a0 != 0) {
    self->unk_a0 = 0;
  }
  return;
}
