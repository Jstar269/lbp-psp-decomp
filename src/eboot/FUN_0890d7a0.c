/* LBPMATCH module=EBOOT.BIN start=0x0890d7a0 end=0x0890d7e8 symbol=FUN_0890d7a0 lang=c99 cc=gcc171-Os rodata=0x08bb4f8c */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review. */
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

extern float DAT_08bdb5dc;
extern undefined4 FUN_08a50fbc();

float FUN_0890d7a0(int param_1)
{
  float fVar1;
  
  FUN_08a50fbc();
  if (*(uchar *)(param_1 + 0x1d) == '\0') {
    fVar1 = 0.87f;
  }
  else {
    fVar1 = DAT_08bdb5dc * 0.87f;
  }
  return fVar1;
}
