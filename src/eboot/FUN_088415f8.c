/* LBPMATCH module=EBOOT.BIN start=0x088415f8 end=0x08841634 symbol=FUN_088415f8 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Returns 1 when the byte at +4 is set; otherwise 1 only if FUN_089e53dc(DAT_08be8600) is not 0. */
extern unsigned int DAT_08be8600;
extern int FUN_089e53dc();

unsigned int FUN_088415f8(unsigned char *self)
{
  int status;
  unsigned int result;

  result = 1;
  if (self[4] == '\0') {
    status = FUN_089e53dc(DAT_08be8600);
    result = 0;
    if (status != 0) {
      result = 1;
    }
  }
  return result;
}
