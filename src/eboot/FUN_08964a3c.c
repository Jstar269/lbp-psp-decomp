/* LBPMATCH module=EBOOT.BIN start=0x08964a3c end=0x08964a9c symbol=FUN_08964a3c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern struct ModeObj *DAT_08be8510;
extern int FUN_0880b31c();

struct ModeObj {
  unsigned char unk_00[0x2e0];
  int unk_2e0;   /* +0x2e0 */
};

struct IdHolder {
  unsigned int unk_00;
  unsigned int id;   /* +4 */
};

/* Sets id to 0x8a, or to 0x8c when the global object exists and either its +0x2e0 is 1 or
   FUN_0880b31c(global) is nonzero. Always returns 1. */
unsigned int FUN_08964a3c(struct IdHolder *self)
{
  struct ModeObj *global;
  int flag;

  global = DAT_08be8510;
  flag = global != 0;
  self->id = 0x8a;
  if (flag && (global->unk_2e0 == 1 || FUN_0880b31c(global) != 0)) {
    self->id = 0x8c;
  }
  return 1;
}
