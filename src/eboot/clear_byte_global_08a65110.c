/* LBPMATCH module=EBOOT.BIN start=0x08a65110 end=0x08a6514c symbol=FUN_08a65110 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): retail zeroes DAT_08bf6c58 with sb, so the translation's undefined4 extern becomes a byte; exact match verified; names and types await human review. */
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

extern undefined DAT_08bf6c58;
extern int FUN_08a3b778();
extern undefined4 FUN_08a50fbc();
extern void FUN_08a52140();

void FUN_08a65110(void)
{
  int iVar1;
  int iVar2;
  
  DAT_08bf6c58 = 0;
  iVar1 = FUN_08a50fbc();
  iVar2 = FUN_08a3b778(2);
  FUN_08a52140(iVar1,*(int *)(iVar2 + 4));
  return;
}
