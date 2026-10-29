/* LBPMATCH module=EBOOT.BIN start=0x08883b08 end=0x08883ba0 symbol=FUN_08883b08 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp8e, Codex GPT-6): restored weak function availability check; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bedfac;
extern int * DAT_08bedfb4;
extern undefined DAT_08bee04c;
extern void FUN_088829e8(void) __attribute__((weak));
extern undefined4 FUN_08849ff0();
extern uint * FUN_08b9eb88();

void FUN_08883b08(void)
{
  int iVar1;
  
  FUN_08b9eb88((uint *)&DAT_08bee04c,0,3);
  if (DAT_08bedfac - 1U < 3) {
    if (((DAT_08bedfb4 != (int *)0x0) && FUN_088829e8 && (iVar1 = FUN_08849ff0((int)DAT_08bedfb4), iVar1 != 0)) &&
       (DAT_08bedfb4 != (int *)0x0)) {
      (**(code **)(*DAT_08bedfb4 + 0x30))(DAT_08bedfb4);
    }
    DAT_08bedfac = 4;
  }
  return;
}



