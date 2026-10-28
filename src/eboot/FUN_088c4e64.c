/* LBPMATCH module=EBOOT.BIN start=0x088c4e64 end=0x088c4ea0 symbol=FUN_088c4e64 lang=c99 cc=gcc410-Os */
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

extern undefined4 * FUN_0895a96c();
extern void FUN_0895b728();

void FUN_088c4e64(void)
{
  undefined4 *puVar1;
  
  puVar1 = FUN_0895a96c();
  if (*(uchar *)(puVar1 + 0x14) != '\0') {
    puVar1 = FUN_0895a96c();
    FUN_0895b728((int)puVar1);
    return;
  }
  return;
}
