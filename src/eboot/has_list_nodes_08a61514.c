/* LBPMATCH module=EBOOT.BIN start=0x08a61514 end=0x08a61538 symbol=FUN_08a61514 cc=gcc404xs-O2 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g3) corrected by hand (lane lbp3c, Claude Sonnet 5.5): compiled with cc=gcc404xs-O2 (batch hint -Os did not reproduce the loop layout) and compared the sentinel on the left; exact match verified; names and types await human review. */
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


bool FUN_08a61514(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = *(int **)(param_1 + 0x234);
  int *end = (int *)(param_1 + 0x234);
  while (end != piVar2) {
    piVar2 = (int *)*piVar2;
    iVar1++;
  }

  return iVar1 != 0;
}
