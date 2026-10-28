/* LBPMATCH module=EBOOT.BIN start=0x089fbc34 end=0x089fbc48 symbol=FUN_089fbc34 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Forwards to FUN_089fbab0 with the last three integer arguments reversed and a trailing flag of 1. */
extern void FUN_089fbab0(float scale, int arg_c, int arg_b, int arg_a, int arg_d, char flag);

void FUN_089fbc34(float scale, int arg_a, int arg_b, int arg_c, int arg_d)
{
  FUN_089fbab0(scale, arg_c, arg_b, arg_a, arg_d, '\x01');
  return;
}
