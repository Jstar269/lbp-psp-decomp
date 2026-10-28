/* LBPMATCH module=EBOOT.BIN start=0x0885deb0 end=0x0885defc symbol=FUN_0885deb0 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct StateObj {
  char unk_00[200];
  int unk_c8;
};

extern int FUN_08878ea8();

/* 1 when FUN_08878ea8() is non-zero and the word at +0xc8 is neither 2 nor 9. */
int FUN_0885deb0(struct StateObj *self)
{
  int flag;

  flag = FUN_08878ea8();
  if (((flag != 0) && (self->unk_c8 != 2)) && (self->unk_c8 != 9)) {
    return 1;
  }
  return 0;
}
