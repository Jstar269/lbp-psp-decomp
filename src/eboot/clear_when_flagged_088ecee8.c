/* LBPMATCH module=EBOOT.BIN start=0x088ecee8 end=0x088ecf6c symbol=FUN_088ecee8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): replaced the shift test with a bit-field struct read into a local, and the short compare with ushort 0xffff; matching idiom: bit field read into a local before the test; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08beed14;
extern undefined4 FUN_088d7f9c();
extern int FUN_088dc4b4();
extern void FUN_088ece00();

struct Flags { unsigned lo : 15; unsigned a : 1; unsigned rest : 16; };

void FUN_088ecee8(int param_1)
{
  int iVar1;
  uint a = ((struct Flags *)(param_1 + 0xd0))->a;
  
  if (((a &&
       (iVar1 = FUN_088dc4b4(DAT_08beed14), *(int *)(iVar1 + 4) == 3)) &&
      (iVar1 = FUN_088d7f9c(), *(ushort *)(*(int *)(iVar1 + 0x18) + 6) == 0xffff)) &&
     (*(uchar *)(param_1 + 0x8c) != '\0')) {
    FUN_088ece00(param_1,'\0');
    return;
  }
  return;
}
