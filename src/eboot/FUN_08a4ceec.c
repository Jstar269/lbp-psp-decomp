/* LBPMATCH module=EBOOT.BIN start=0x08a4ceec end=0x08a4cf0c symbol=FUN_08a4ceec lang=c99 cc=gcc402x-O2 */
/* Clone of src/eboot/FUN_08a4c8f8.c (lbpclone.py tag r-rd3a): addresses substituted; exact match verified; names and types await human review. */
extern void FUN_08a4cd24();
extern void FUN_08a4c794();

/* The word at +0x34 of the object self points at selects between the two helpers. */
struct InnerObj {
  unsigned char unk_00[0x34];
  int unk_34;   /* +0x34 */
};

struct OuterObj {
  struct InnerObj *inner;
};

void FUN_08a4ceec(struct OuterObj *self, int arg)
{
  if (self->inner->unk_34 != 0) {
    FUN_08a4c794(arg);
    return;
  }
  FUN_08a4cd24(arg);
}
