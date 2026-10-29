/* LBPMATCH module=EBOOT.BIN start=0x088e7658 end=0x088e76b4 symbol=FUN_088e7658 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): the indirect virtual call passes its object (loaded into a0): retail's this argument was dropped; exact match verified; names and types await human review. */
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

extern undefined DAT_08beedf4;
extern int FUN_088e7604();

void FUN_088e7658(uint *param_1,int *param_2)
{
  int iVar1;
  uint local_20 [4];
  
  if (*param_2 != 0) {
    local_20[0] = *param_1;
    iVar1 = FUN_088e7604((int)&DAT_08beedf4,local_20);
    int *obj = *(int **)(iVar1 + 0x14);
    (**(void (**)(int *))(*obj + 0xc))(obj);
    *param_2 = 0;
  }
  return;
}
