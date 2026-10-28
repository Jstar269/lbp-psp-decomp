/* LBPMATCH module=EBOOT.BIN start=0x08995cb4 end=0x08995d04 symbol=FUN_08995cb4 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): pass the object to the first call; exact match verified; names and types await human review. */
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

extern undefined * DAT_08be8480;
extern undefined4 DAT_08be8510;
extern void FUN_0880b148();
extern void FUN_08974640();
extern void FUN_08995b54();

void FUN_08995cb4(int param_1)
{
  if ((DAT_08be8480 != 0) && (*(uchar *)(DAT_08be8480 + 4) != '\0')) {
    FUN_0880b148(DAT_08be8510,0);
  }
  FUN_08995b54(param_1);
  FUN_08974640(param_1);
  return;
}



