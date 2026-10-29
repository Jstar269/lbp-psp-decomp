/* LBPMATCH module=EBOOT.BIN start=0x08959698 end=0x089596cc symbol=FUN_08959698 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): DAT_08befaf0 declared as a byte (retail stores it with sb); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bedb18;
extern undefined DAT_08befac8;
extern undefined DAT_08befaf0;
extern void FUN_089265c8();

void FUN_08959698(void)
{
  FUN_089265c8(DAT_08bedb18,&DAT_08befac8,0);
  DAT_08befaf0 = 0;
  return;
}
