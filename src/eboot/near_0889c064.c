/* LBPMATCH module=EBOOT.BIN start=0x0889c064 end=0x0889c094 symbol=FUN_0889c064 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): the local buffer is 76 words (first element passed as a 32-bit value: lw, not lhu); exact match verified; names and types await human review. */
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
extern void FUN_08aee0ec();
extern void FUN_08aefca8();

void FUN_0889c064(void)
{
  undefined4 local_140 [76];
  
  FUN_08aee0ec((undefined4 *)local_140,(undefined4 *)0x0);
  FUN_08aefca8(&DAT_08bee268,local_140[0]);
  return;
}
