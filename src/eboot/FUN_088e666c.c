/* LBPMATCH module=EBOOT.BIN start=0x088e666c end=0x088e66cc symbol=FUN_088e666c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Forwards `arg` and `data` to FUN_08881018 on the sub-object at +0x40 (after FUN_08881bf8 when arg is 4)
   and sets the word at +0x48 to 1. */
struct Owner40 {
  char pad[0x40];
  int sub_object;            /* +0x40 */
  char pad2[4];
  int flag_48;               /* +0x48 */
};

extern int FUN_08881018();
extern void FUN_08881bf8();

void FUN_088e666c(struct Owner40 *self, int arg, unsigned int *data)
{
  if (arg == 4) {
    FUN_08881bf8(self->sub_object, 4);
  }
  self->flag_48 = 1;
  FUN_08881018(self->sub_object, arg, data, '\0');
  return;
}
