/* LBPMATCH module=EBOOT.BIN start=0x0889be7c end=0x0889bf30 symbol=FUN_0889be7c lang=c99 */
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

extern undefined DAT_08bee268;
extern undefined DAT_08bee2a7;
extern undefined DAT_08bee2a8;
extern undefined DAT_08bee2c7;
extern undefined4 DAT_08bee2c8;
extern uint * FUN_08b9eb88();
extern char * FUN_08ba10e8();

void FUN_0889be7c(undefined4 param_1,undefined4 param_2,char *param_3,char *param_4)
{
  DAT_08bee2c8 = param_2;
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    FUN_08b9eb88((uint *)&DAT_08bee268,0,0x40);
  }
  else {
    FUN_08ba10e8(&DAT_08bee268,param_3,0x40);
  }
  if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
    FUN_08b9eb88((uint *)&DAT_08bee2a8,0,0x20);
  }
  else {
    FUN_08ba10e8(&DAT_08bee2a8,param_4,0x20);
  }
  DAT_08bee2a7 = 0;
  DAT_08bee2c7 = 0;
  return;
}

// Baseline generated candidate; 31 differing words. Tested primary and O2 profiles; control flow and types need reconstruction.
// near miss from lane lbp8f (unreviewed)
