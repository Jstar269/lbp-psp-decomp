/* LBPMATCH module=EBOOT.BIN start=0x08a96cb8 end=0x08a96d30 symbol=FUN_08a96cb8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern void FUN_08a0af3c(float value,int self);
extern void FUN_08a94af4();

typedef struct Body {
  char pad_00[0x18];
  float unk_18;
  char pad_1c[4];
  float unk_20;
} Body;

/* An object tying two bodies together (first/second at +4/+8). */
typedef struct PairObj {
  char pad_00[4];
  Body *first;
  Body *second;
  char pad_0c[0x58];
  int flags;           /* bit 7 (0x80) set: take the FUN_08a0af3c path instead */
  char pad_68[0x64];
  float amount;
} PairObj;

void FUN_08a96cb8(PairObj *self)
{
  Body *first;
  Body *second;
  float second_unk_18;
  float amount;

  FUN_08a94af4(self);
  amount = self->amount;
  if (-1 < (self->flags << 0x18)) {
    first = self->first;
    second = self->second;
    second_unk_18 = second->unk_18;
    /* apply +/- amount scaled by each body's unk_18 to its unk_20 */
    first->unk_20 = first->unk_20 - amount * first->unk_18;
    second->unk_20 = second->unk_20 + amount * second_unk_18;
    return;
  }
  FUN_08a0af3c(amount,(int)self);
  return;
}
