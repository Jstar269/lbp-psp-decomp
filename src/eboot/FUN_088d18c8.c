/* LBPMATCH module=EBOOT.BIN start=0x088d18c8 end=0x088d18ec symbol=FUN_088d18c8 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_088cf348.c (lbpclone.py tag c5): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08beee0c;
extern void FUN_088d17a8();
extern void FUN_088ea7b8();

void FUN_088d18c8(void)
{
  FUN_088ea7b8(DAT_08beee0c);
  FUN_088d17a8();
  return;
}
