/* LBPMATCH module=EBOOT.BIN start=0x08a76778 end=0x08a76818 symbol=FUN_08a76778 lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3b, Claude Sonnet 5.5): gcc404xs-O2 header; virtual call passes the object as first argument; exact match verified; names and types await human review. */
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

extern void FUN_0895541c();
extern void FUN_08a0d114();
extern void FUN_08a34774();
extern void FUN_08a55200();
extern void FUN_08a552e8();
extern void FUN_08a55f00();
extern void FUN_08a5676c();

void FUN_08a76778(int param_1,int *param_2)
{
  int iVar1;
  
  FUN_08a34774(param_1,param_2,0x4e545350);
  FUN_08a55f00(param_2,(undefined4 *)(param_1 + 0x19c));
  FUN_08a552e8(param_2,param_1,param_1 + 0x1a8);
  FUN_08a5676c(param_2,(undefined4 *)(param_1 + 0x1e0));
  int *obj = *(int **)(param_1 + 400);
  int *vtbl = (int *)*obj;
  typedef int (*Fn)(int *);
  Fn fn = (Fn)vtbl[9];
  iVar1 = fn(obj);
  if ((*(uint *)(iVar1 + 0x5c) & 1) != 0) {
    FUN_08a0d114(iVar1);
  }
  FUN_08a55200(param_2,iVar1);
  FUN_0895541c(param_2);
  return;
}
