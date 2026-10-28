/* LBPMATCH module=EBOOT.BIN start=0x08977e40 end=0x08977f04 symbol=FUN_08977e40 lang=c99 cc=gcc402t-Os rodata=0x08bbd7ec */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
/* Characters in the Unicode private-use block starting at 0xe000 map to small codes; the first two
   are resolved by helper calls, anything else not listed gives the fallback. */
#define PRIVATE_USE_BASE 0xe000
#define UNMAPPED_CODE 0xa4

extern unsigned int FUN_08970cac();
extern unsigned int FUN_08970f7c();

unsigned int FUN_08977e40(unsigned short character)
{
  unsigned int result;

  result = UNMAPPED_CODE;
  switch(character) {
  case PRIVATE_USE_BASE:
    result = FUN_08970cac();
    return result;
  case PRIVATE_USE_BASE + 1:
    result = FUN_08970f7c();
    return result;
  case PRIVATE_USE_BASE + 2:
    result = 0x21;
    break;
  case PRIVATE_USE_BASE + 3:
    result = 0x22;
    break;
  case PRIVATE_USE_BASE + 4:
    result = 0x23;
    break;
  case PRIVATE_USE_BASE + 5:
    result = 0x24;
    break;
  case PRIVATE_USE_BASE + 6:
    result = 0x25;
    break;
  case PRIVATE_USE_BASE + 7:
    result = 0x26;
    break;
  case PRIVATE_USE_BASE + 8:
    result = 0x27;
    break;
  case PRIVATE_USE_BASE + 9:
    result = 0x28;
    break;
  case PRIVATE_USE_BASE + 10:
    result = 0x29;
    break;
  case PRIVATE_USE_BASE + 11:
    result = 0x2a;
    break;
  case PRIVATE_USE_BASE + 12:
    result = 0x2b;
    break;
  case PRIVATE_USE_BASE + 13:
    result = 0x2c;
    break;
  case PRIVATE_USE_BASE + 14:
    result = 0x2d;
    break;
  case PRIVATE_USE_BASE + 15:
    result = 0x1f;
    break;  case PRIVATE_USE_BASE + 16:
    result = 0x20;
  }
  return result;
}
