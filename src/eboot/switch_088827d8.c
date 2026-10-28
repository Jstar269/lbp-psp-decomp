/* LBPMATCH module=EBOOT.BIN start=0x088827d8 end=0x0888287c symbol=FUN_088827d8 lang=c99 rodata=0x08bb0c10 */
/* Ghidra pseudocode (lbpgen.py tag g13) corrected by hand (lane lbp1c, Codex GPT-6): place default after the cases; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;


undefined4 FUN_088827d8(undefined4 param_1)
{
  switch(param_1) {
  case 0:
    return 0xe;
  case 1:
    return 4;
  case 3:
    return 3;
  case 4:
    return 0xc;
  case 5:
    return 2;
  case 6:
    return 5;
  case 7:
    return 0;
  case 8:
    return 9;
  case 9:
    return 6;
  case 10:
    return 0xf;
  case 0xb:
    return 0x10;
  case 0xc:
    return 7;
  case 0xd:
    return 8;
  case 0xe:
    return 0xd;
  case 0x10:
    return 10;
  default:
    return 1;
  }
}

