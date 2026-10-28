/* LBPMATCH module=EBOOT.BIN start=0x089085d8 end=0x08908628 symbol=FUN_089085d8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Composite {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  char pad_0c[4];
  char unk_10[0x18];        /* initialised by FUN_08a9c014 */
  char unk_28[0x18];        /* initialised by FUN_08a9c014 */
  char unk_40[0x1c];        /* initialised by FUN_08921788 */
  char unk_5c[0x1c];        /* initialised by FUN_08921788 */
  unsigned int unk_78;
};

extern void FUN_08921788();
extern void FUN_08a9c014();

void FUN_089085d8(struct Composite *self, unsigned int value_08, unsigned int value_04)
{
  self->unk_04 = value_04;
  self->unk_08 = value_08;
  self->unk_00 = 0;
  FUN_08a9c014(self->unk_10);
  FUN_08a9c014(self->unk_28);
  FUN_08921788(self->unk_40);
  FUN_08921788(self->unk_5c);
  self->unk_78 = 0;
}
