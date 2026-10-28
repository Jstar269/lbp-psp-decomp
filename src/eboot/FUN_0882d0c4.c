/* LBPMATCH module=EBOOT.BIN start=0x0882d0c4 end=0x0882d228 symbol=FUN_0882d0c4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g9); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Releases (via FUN_08a9e0c4) and clears every owned handle slot of self; slots 0x54/0x58/0x60 are not touched. */
struct Owner0882d0c4 {
  char pad[0x40];
  unsigned int unk_40;
  unsigned int unk_44;
  unsigned int unk_48;
  unsigned int unk_4c;
  unsigned int unk_50;
  char pad_54[0x8];
  unsigned int unk_5c;
  char pad_60[0x4];
  unsigned int unk_64;
  unsigned int unk_68;
  unsigned int unk_6c;
  unsigned int unk_70;
  unsigned int unk_74;
  unsigned int unk_78;
  unsigned int unk_7c;
  unsigned int unk_80;
  unsigned int unk_84;
  unsigned int unk_88;
};

extern void FUN_08a9e0c4(unsigned int handle);

void FUN_0882d0c4(struct Owner0882d0c4 *self)
{
  unsigned int handle;

  if (self->unk_40 != 0) {
    FUN_08a9e0c4(self->unk_40);
  }
  self->unk_40 = 0;
  handle = self->unk_44;
  if (handle != 0) {
    FUN_08a9e0c4(handle);
  }
  self->unk_44 = 0;
  if (self->unk_48 != 0) {
    FUN_08a9e0c4(self->unk_48);
  }
  self->unk_48 = 0;
  if (self->unk_4c != 0) {
    FUN_08a9e0c4(self->unk_4c);
  }
  self->unk_4c = 0;
  if (self->unk_50 != 0) {
    FUN_08a9e0c4(self->unk_50);
  }
  self->unk_50 = 0;
  if (self->unk_5c != 0) {
    FUN_08a9e0c4(self->unk_5c);
  }
  self->unk_5c = 0;
  if (self->unk_64 != 0) {
    FUN_08a9e0c4(self->unk_64);
  }
  self->unk_64 = 0;
  if (self->unk_68 != 0) {
    FUN_08a9e0c4(self->unk_68);
  }
  self->unk_68 = 0;
  if (self->unk_6c != 0) {
    FUN_08a9e0c4(self->unk_6c);
  }
  self->unk_6c = 0;
  if (self->unk_70 != 0) {
    FUN_08a9e0c4(self->unk_70);
  }
  self->unk_70 = 0;
  if (self->unk_74 != 0) {
    FUN_08a9e0c4(self->unk_74);
  }
  self->unk_74 = 0;
  if (self->unk_78 != 0) {
    FUN_08a9e0c4(self->unk_78);
  }
  self->unk_78 = 0;
  if (self->unk_7c != 0) {
    FUN_08a9e0c4(self->unk_7c);
  }
  self->unk_7c = 0;
  if (self->unk_80 != 0) {
    FUN_08a9e0c4(self->unk_80);
  }
  self->unk_80 = 0;
  if (self->unk_84 != 0) {
    FUN_08a9e0c4(self->unk_84);
  }
  self->unk_84 = 0;
  if (self->unk_88 != 0) {
    FUN_08a9e0c4(self->unk_88);
  }
  self->unk_88 = 0;
}
