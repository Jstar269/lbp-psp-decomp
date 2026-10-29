/* LBPMATCH module=EBOOT.BIN start=0x08a647ec end=0x08a6482c symbol=FUN_08a647ec lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp4c, Claude Sonnet 5.5): rewritten with a struct for the global object and early returns, header cc=gcc404xs-O2; exact match verified; names and types await human review. */
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

struct Obj { uchar pad[4]; uchar flag; };
extern struct Obj * DAT_08be8480;

void FUN_08a647ec(undefined4 param_1,int param_2,int param_3)
{
  if (*(int *)(param_2 + 0x44) != 0x26) {
    return;
  }
  if (DAT_08be8480 != 0 && DAT_08be8480->flag != 0) {
    return;
  }
  *(uint *)(param_3 + 0xac) |= 1;
}
