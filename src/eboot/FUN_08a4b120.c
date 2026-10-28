/* LBPMATCH module=EBOOT.BIN start=0x08a4b120 end=0x08a4b17c symbol=FUN_08a4b120 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Inner {
  char pad_00[0x18];
  unsigned int unk_18;
};

struct Target {
  char pad_00[0x21c];
  unsigned char unk_21c;     /* ANDed with the result of FUN_089eacc4 */
};

extern unsigned char FUN_089eacc4();
extern unsigned char *FUN_089ecaa8();

void FUN_08a4b120(struct Inner **ref, struct Target *target)
{
  unsigned char old_flag;
  unsigned char ok;
  unsigned int value;

  value = (*ref)->unk_18;
  if (value != 0) {
    FUN_089ecaa8();
    old_flag = target->unk_21c;
    ok = FUN_089eacc4(value);
    target->unk_21c = (old_flag & ok) != 0;
  }
}
