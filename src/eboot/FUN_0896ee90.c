/* LBPMATCH module=EBOOT.BIN start=0x0896ee90 end=0x0896eebc symbol=FUN_0896ee90 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x2c];
  int table_2c[1];
};

extern void FUN_08978658();
extern int FUN_08978ef0();

void FUN_0896ee90(struct Obj *self, int index, int arg)
{
  int result;

  result = FUN_08978ef0(self->table_2c[index], arg);
  FUN_08978658(result);
  return;
}
