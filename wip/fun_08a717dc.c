/* LBPMATCH module=EBOOT.BIN start=0x08a717dc end=0x08a71890 symbol=FUN_08a717dc lang=c99 cc=gcc404xs-O2 */
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


void FUN_08a717dc(int *param_1)
{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *param_1;
  while( true ) {
    puVar1 = (uint *)(**(code **)(iVar2 + 0x94))(param_1);
    piVar3 = (int *)param_1[0x27];
    puVar1[0x2c] = 0;
    *puVar1 = *puVar1 & 0xffffffd7;
    while (piVar3 != param_1 + 0x27) {
      puVar1 = (uint *)(**(code **)(*(int *)piVar3[2] + 0x94))();
      piVar3 = (int *)*piVar3;
      puVar1[0x2c] = 0;
      *puVar1 = *puVar1 & 0xffffffd7;
    }
    param_1 = (int *)param_1[0x26];
    if (param_1 == (int *)0x0) break;
    iVar2 = *param_1;
  }
  return;
}

// Baseline generated candidate; 30 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
