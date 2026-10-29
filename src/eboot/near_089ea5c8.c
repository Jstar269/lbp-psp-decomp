/* LBPMATCH module=EBOOT.BIN start=0x089ea5c8 end=0x089ea630 symbol=FUN_089ea5c8 lang=c99 cc=gcc404xs-O2 rodata=0x08bc2720 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3a, Claude Sonnet 5.5): rewritten as a switch with an explicit result; needs cc=gcc404xs-O2 (at -Os GCC emits no jump table for this switch) and the case labels in the order that places the blocks like retail; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

undefined4 FUN_089ea5c8(undefined4 param_1)
{
  switch(param_1) {
  case 7:
    param_1 = 2;
    break;
  case 5:
    param_1 = 0;
    break;
  case 0x16:
    param_1 = 0x17;
    break;
  case 0x12:
    param_1 = 0x13;
    break;
  case 6:
    param_1 = 1;
    break;
  }
  return param_1;
}
