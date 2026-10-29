/* LBPMATCH module=EBOOT.BIN start=0x0897a15c end=0x0897a248 symbol=FUN_0897a15c lang=c99 */
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

extern undefined4 * FUN_0896b4a0();
extern void FUN_08970b6c();
extern undefined4 * FUN_08979514();
extern void FUN_089797f0();

void FUN_0897a15c(int param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int local_24;
  undefined4 *local_28;
  undefined4 *local_2c;
  
  while( true ) {
    iVar1 = *param_2;
    uVar2 = 0x4a39;
    if (iVar1 == 0) break;
    local_24 = param_2[1];
    param_2 = param_2 + 2;
    if ((param_3 != 1) && (uVar2 = 0x4a3a, param_3 != 2)) {
      uVar2 = 19000;
    }
    FUN_0896b4a0(&local_28,iVar1);
    FUN_08979514(&local_2c,uVar2,&local_24);
    FUN_089797f0(param_1,(int *)&local_28,&local_2c,0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_08970b6c(local_2c);
    }
    if (local_28 != (undefined4 *)0x0) {
      FUN_08970b6c(local_28);
    }
  }
  return;
}

// Baseline generated candidate; 40 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
