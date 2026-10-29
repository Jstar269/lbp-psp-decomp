/* LBPMATCH module=EBOOT.BIN start=0x089b3ab0 end=0x089b3bec symbol=FUN_089b3ab0 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4a, Claude Sonnet 5.5): typed the array at +0x90 as {int **data; short first, count;} and wrote the empty counting loop as a for loop (retail keeps it); exact match verified; names and types await human review. */
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

struct Arr { int **data; short first; short count; };
extern int * FUN_089ae920();
extern int FUN_089af564();
extern void FUN_089b370c();
extern void FUN_089d9260();

void FUN_089b3ab0(char *param_1)
{
  int *piVar3;
  char *iVar4;
  
  piVar3 = FUN_089ae920('\x01');
  iVar4 = FUN_089af564(0x11,1,0x2a,-1,1,0);
  *(undefined4 *)(iVar4 + 0x24) = 0x4000;
  FUN_089d9260((int)piVar3,iVar4);
  iVar4 = FUN_089af564(0x11,1,0x29,-1,1,0);
  *(undefined4 *)(iVar4 + 0x24) = 0x8000;
  FUN_089d9260((int)piVar3,iVar4);
  iVar4 = FUN_089af564(0x11,1,0x26,-1,1,0);
  *(undefined4 *)(iVar4 + 0x24) = 0x10000;
  FUN_089d9260((int)piVar3,iVar4);
  iVar4 = FUN_089af564(0x11,1,0x25,-1,1,0);
  *(undefined4 *)(iVar4 + 0x24) = 0x20000;
  FUN_089d9260((int)piVar3,iVar4);
  {
    struct Arr *a = (struct Arr *)(param_1 + 0x90);
    int i;
    a->data[4 - a->first] = piVar3;
    for (i = 0; i < a->count; i++) {
    }
  }
  FUN_089b370c(param_1,0x327,0x328,(int)piVar3,300);
  return;
}
