/* LBPMATCH module=EBOOT.BIN start=0x08841554 end=0x08841590 symbol=FUN_08841554 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Returns 1 when the byte at +6 is set; otherwise 1 only if FUN_089e540c(DAT_08be8600) is 0. */
extern unsigned int DAT_08be8600;
extern int FUN_089e540c();

unsigned int FUN_08841554(unsigned char *self)
{
  int status;
  unsigned int result;

  result = 1;
  if (self[6] == '\0') {
    status = FUN_089e540c(DAT_08be8600);
    result = 0;
    if (status == 0) {
      result = 1;
    }
  }
  return result;
}
