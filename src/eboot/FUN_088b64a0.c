/* LBPMATCH module=EBOOT.BIN start=0x088b64a0 end=0x088b64c8 symbol=FUN_088b64a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be84a4;
extern void FUN_088b2a08();
extern void FUN_0896f114();
extern void FUN_089f9580();

void FUN_088b64a0(int param_1)
{
  FUN_088b2a08(param_1);
  FUN_089f9580(DAT_08be84a4);
  FUN_0896f114();
  return;
}
