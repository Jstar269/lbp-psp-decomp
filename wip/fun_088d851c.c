/* LBPMATCH module=EBOOT.BIN start=0x088d851c end=0x088d85d8 symbol=FUN_088d851c lang=c99 */
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

extern void FUN_08b88f70();

void FUN_088d851c(undefined4 *param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 != param_2) {
    puVar3 = (undefined4 *)*param_1;
    puVar1 = (undefined4 *)*param_2;
    while (puVar3 != param_1) {
      if (puVar1 == param_2) {
        return;
      }
      if (*(float *)(puVar1[2] + 4) < *(float *)(puVar3[2] + 4)) {
        puVar2 = (undefined4 *)*puVar1;
        FUN_08b88f70((int)puVar3,(int)puVar1,(int)puVar2);
        puVar1 = puVar2;
      }
      else {
        puVar3 = (undefined4 *)*puVar3;
      }
    }
    if (puVar1 != param_2) {
      FUN_08b88f70((int)param_1,(int)puVar1,(int)param_2);
      return;
    }
  }
  return;
}



// Os 30 differing words: loop entry and update layout; O2 57.
// near miss from lane lbp8e (unreviewed)
