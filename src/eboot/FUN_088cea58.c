/* LBPMATCH module=EBOOT.BIN start=0x088cea58 end=0x088ceadc symbol=FUN_088cea58 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
struct FlaggedObject {
  char unk_000[0x100];
  unsigned int unk_100;        /* copied into the temporary below */
  unsigned char unk_104;       /* set to 1 at the end */
};

#define TEMP_ID 0x4e26         /* second argument of FUN_088ce9d8; meaning not yet known */

extern void *DAT_08bf03b8;     /* global object that FUN_0896fbd4 acts on */
extern unsigned int *FUN_088ce9d8();
extern void FUN_0896fbd4();
extern void FUN_08970b6c();    /* releases the pointer FUN_088ce9d8 stored in temp[0] */

void FUN_088cea58(struct FlaggedObject *self)
{
  void *global_obj;
  unsigned int *temp[3];
  unsigned int arg;

  global_obj = DAT_08bf03b8;
  arg = self->unk_100;
  FUN_088ce9d8(temp, TEMP_ID, &arg);
  FUN_0896fbd4(global_obj, temp, 1, 0x11);
  if (temp[0] != 0) {
    FUN_08970b6c(temp[0]);
  }
  self->unk_104 = 1;
}
