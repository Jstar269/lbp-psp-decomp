/* LBPMATCH module=EBOOT.BIN start=0x089ea564 end=0x089ea5c8 symbol=FUN_089ea564 lang=c99 cc=gcc404xs-O2 rodata=0x08bc26c0 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3a, Claude Sonnet 5.5): rewritten as a switch with an explicit result; needs cc=gcc404xs-O2 (at -Os GCC emits no jump table) and the case labels in the order that places the blocks like retail; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

undefined4 FUN_089ea564(undefined4 param_1)
{
  switch(param_1) {
  case 2:
    param_1 = 7;
    break;
  case 0:
    param_1 = 5;
    break;
  case 0x17:
    param_1 = 0x16;
    break;
  case 0x13:
    param_1 = 0x12;
    break;
  case 1:
    param_1 = 6;
    break;
  }
  return param_1;
}
