/* LBPMATCH module=EBOOT.BIN start=0x08b8fa74 end=0x08b8fb14 symbol=FUN_08b8fa74 lang=c99 */
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

extern int FUN_08b8f7f0();

undefined4 FUN_08b8fa74(int param_1,int param_2)
{
  char cVar1;
  
  if (param_2 == 0) {
    param_2 = (int)**(char **)(param_1 + 0xc);
    *(char **)(param_1 + 0xc) = *(char **)(param_1 + 0xc) + 1;
  }
  if (param_2 != 0x68) {
    if (param_2 != 0x76) {
      return 0;
    }
    FUN_08b8f7f0(param_1);
    cVar1 = **(char **)(param_1 + 0xc);
    *(char **)(param_1 + 0xc) = *(char **)(param_1 + 0xc) + 1;
    if (cVar1 != '_') {
      return 0;
    }
  }
  FUN_08b8f7f0(param_1);
  cVar1 = **(char **)(param_1 + 0xc);
  *(char **)(param_1 + 0xc) = *(char **)(param_1 + 0xc) + 1;
  if (cVar1 != '_') {
    return 0;
  }
  return 1;
}

// Baseline generated candidate; 28 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
