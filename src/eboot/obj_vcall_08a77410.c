/* LBPMATCH module=EBOOT.BIN start=0x08a77410 end=0x08a7748c symbol=FUN_08a77410 lang=c99 cc=gcc402x-O2 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp2b, DeepSeek through Freebuff): the vtable call at +0x24 passes its object as `this`, so the object pointer is passed explicitly instead of being left in a scratch register; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_08a10f1c();
extern void FUN_08a115e0();
extern void FUN_08a7717c();
extern void FUN_08a9a5c8();
extern void FUN_08a7781c();

void FUN_08a77410(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_08a9a5c8((int *)param_1);
  puVar1 = FUN_08a10f1c();
  FUN_08a115e0((int)puVar1,*(undefined4 *)(param_1 + 0x19c),*(undefined4 *)(param_1 + 0x1a0),
               *(undefined4 *)(param_1 + 400),param_1,0xffffffff);
  FUN_08a7717c((undefined4 *)(param_1 + 0x180),(undefined4 *)(param_1 + 0x184),(undefined4 *)(param_1 + 0x188),(int)param_1 + 396);
  {
    void *obj = *(void **)(param_1 + 400);
    void **vt = *(void ***)obj;
    iVar2 = ((int (*)(void *))vt[9])(obj);
  }
  *(code **)(iVar2 + 0x38) = FUN_08a7781c;
  return;
}
