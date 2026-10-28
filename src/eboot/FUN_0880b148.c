/* LBPMATCH module=EBOOT.BIN start=0x0880b148 end=0x0880b178 symbol=FUN_0880b148 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Inner {
  char pad_00[0x2b6];
  unsigned char unk_2b6;
};

struct Obj {
  char pad_00[4];
  struct Inner *unk_04;
  char pad_08[0x1d9];
  unsigned char flag;       /* +0x1e1, mirrored into unk_04->unk_2b6 */
  char pad_1e2[2];
  int unk_1e4;
};

void FUN_0880b148(struct Obj *self, unsigned char flag)
{
  self->flag = flag;
  if (self->unk_04 != 0) {
    self->unk_04->unk_2b6 = flag;
  }
  if (self->flag == 1) {
    self->unk_1e4 = 3;
  }
}
