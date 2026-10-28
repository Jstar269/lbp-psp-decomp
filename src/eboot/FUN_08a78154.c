/* LBPMATCH module=EBOOT.BIN start=0x08a78154 end=0x08a781d8 symbol=FUN_08a78154 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int DAT_08bef408;
extern void FUN_08913dd8();
extern void *FUN_08914a7c();
extern int FUN_08914e94();
extern void FUN_08a78000();

struct Obj6b4 {
  unsigned char unk_00[0x6b4];
  int unk_6b4;   /* +0x6b4: nothing more happens when this is 0 */
  int unk_6b8;   /* +0x6b8: cleared first */
};

void FUN_08a78154(struct Obj6b4 *self)
{
  void *first;
  void *second;
  int value;

  self->unk_6b8 = 0;
  FUN_08a78000(self, 1);
  if (self->unk_6b4 == 0) {
    return;
  }
  first = FUN_08914a7c();
  second = FUN_08914a7c();
  value = FUN_08914e94(second, DAT_08bef408);
  FUN_08913dd8(first, 0, value, 6, 0, 0, 0x400, 0);
}
