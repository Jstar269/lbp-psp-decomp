/* LBPMATCH module=EBOOT.BIN start=0x08a4d504 end=0x08a4d56c symbol=FUN_08a4d504 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_088050b8();
extern void FUN_08a4c794();
extern void FUN_08a4d370();

/* Class-like record; the word at +0x34 selects which of the two handlers runs. */
struct Kind {
  char unk_00[0x34];
  int unk_34;
};

struct Host {
  struct Kind *kind;
};

struct Target {
  char unk_00[0x1ec];
  int *owned;
};

void FUN_08a4d504(struct Host *host,struct Target *target)
{
  int *owned;

  owned = target->owned;
  target->owned = 0;
  if (owned != (int *)0x0) {
    FUN_088050b8(owned);
  }
  if (host->kind->unk_34 != 0) {
    FUN_08a4c794(target);
    return;
  }
  FUN_08a4d370(target);
  return;
}
