/* LBPMATCH module=EBOOT.BIN start=0x08913dbc end=0x08913dd8 symbol=FUN_08913dbc lang=c99 cc=gcc171-Os */
/* Clone of src/eboot/FUN_08913d58.c (lbpclone.py tag r-rd3b): addresses substituted; exact match verified; names and types await human review. */

struct Obj {
  char pad_00[0x30];
  int unk_30;
};

extern unsigned char FUN_0891895c();

void FUN_08913dbc(struct Obj *self)
{
  FUN_0891895c(self->unk_30);
}
