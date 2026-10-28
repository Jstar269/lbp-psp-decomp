/* LBPMATCH module=EBOOT.BIN start=0x088c8428 end=0x088c8498 symbol=FUN_088c8428 lang=c99 cc=gcc404xs-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g14); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Item {
  char pad_00[0x10];
  int unk_10;
};

struct Target {
  char pad_00[0x60];
  int unk_60;
  char pad_64[0x18];
  char list_7c[8];
  char list_84[8];
};

extern void FUN_088c8398();

/* Append the item to list_84 (unk_10 is 0 or 0x80110327, unk_60 += 1) or else to list_7c (unk_60 += 2). */
void FUN_088c8428(struct Item **ref, struct Target *target)
{
  int new_count;

  if ((*ref)->unk_10 == 0 || (*ref)->unk_10 == 0x80110327) {
    FUN_088c8398(target->list_84, ref);
    new_count = target->unk_60 + 1;
  }
  else {
    FUN_088c8398(target->list_7c, ref);
    new_count = target->unk_60 + 2;
  }
  target->unk_60 = new_count;
}
