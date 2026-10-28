/* LBPMATCH module=EBOOT.BIN start=0x088f7414 end=0x088f7454 symbol=FUN_088f7414 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review. */
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

extern undefined * DAT_08beee0c;
extern undefined DAT_08beee5c;
extern void FUN_088f71f0();

void FUN_088f7414(void)
{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_08beee5c != '\0') {
    DAT_08beee5c = 0;
    if (*(int *)(DAT_08beee0c + 0x1c) != *(int *)(DAT_08beee0c + 0x20)) {
      iVar1 = *(int *)(*(int *)(DAT_08beee0c + 0x20) + -4);
    }
    FUN_088f71f0(iVar1,'\0');
    return;
  }
  return;
}
