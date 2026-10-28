/* LBPMATCH module=EBOOT.BIN start=0x08a3c058 end=0x08a3c0fc symbol=FUN_08a3c058 lang=c99 cc=gcc402x-O2 */
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

extern int FUN_08a3b778();
extern void FUN_08a5c2f4();

void FUN_08a3c058(int param_1,int param_2)
{
  int iVar1;
  
  if (param_2 != 1) {
    if (param_2 < 2) {
      if (param_2 == 0) {
LAB_08a3c0b4:
        iVar1 = FUN_08a3b778(2);
        if (*(char *)(param_1 + 0x290) == '\0') {
          *(undefined1 *)(param_1 + 0x24c) = 1;
          *(undefined1 *)(param_1 + 0x290) = 0;
        }
        else {
          FUN_08a5c2f4(iVar1,param_1);
          *(undefined1 *)(param_1 + 0x24c) = 1;
          *(undefined1 *)(param_1 + 0x290) = 0;
        }
        return;
      }
    }
    else {
      if (param_2 == 4) goto LAB_08a3c098;
      if (param_2 == 6) goto LAB_08a3c0b4;
    }
    return;
  }
LAB_08a3c098:
  *(undefined1 *)(param_1 + 0x24c) = 0;
  return;
}

// best of the profile sweep: cc=gcc402x-O2, 19 differing words left of 41.
// near miss from lane lbp2c (unreviewed)
