/* LBPMATCH module=EBOOT.BIN start=0x089eb478 end=0x089eb4d0 symbol=FUN_089eb478 lang=c99 cc=gcc404xs-O2 */
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

extern void FUN_088b34bc();
extern void FUN_089eb348();

void FUN_089eb478(undefined1 *param_1)
{
  if (param_1[2] == '\0') {
    FUN_089eb348((int)param_1);
    FUN_088b34bc((int *)(param_1 + 0x9c));
    if (param_1[0x195] != '\0') {
      *param_1 = 0;
      return;
    }
  }
  return;
}
// NEAR: cc=gcc404xs-O2 gives the retail layout (duplicated epilogue) but retail schedules 'move s0,a0' before 'sw ra,4(sp)' and fills the beqz delay slot with 'lw ra'; ours keeps move in the delay slot. Tried struct param, local copy, early return, O3/402x/410 profiles: no change.
// near miss from lane lbp4c (unreviewed)
