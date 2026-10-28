/* LBPMATCH module=EBOOT.BIN start=0x088d1120 end=0x088d116c symbol=FUN_088d1120 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): use a byte-sized flag; exact match verified; names and types await human review. */
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

extern undefined DAT_088d1120;
extern undefined DAT_08bec4a8;
extern undefined DAT_08bec4a9;
extern undefined4 DAT_08beee0c;
extern void FUN_088d1034();
extern undefined4 FUN_088e7e24();

void FUN_088d1120(void)
{
  int iVar1;
  
  iVar1 = FUN_088e7e24(DAT_08beee0c,(int)&DAT_088d1120);
  if (iVar1 == 0) {
    DAT_08bec4a8 = 1;
    DAT_08bec4a9 = 0;
    FUN_088d1034();
    return;
  }
  return;
}


