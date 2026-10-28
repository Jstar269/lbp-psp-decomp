/* LBPMATCH module=EBOOT.BIN start=0x088cece0 end=0x088ced20 symbol=FUN_088cece0 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp1b, Codex GPT-6): corrected global byte width; exact match verified; names and types await human review. */
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

extern undefined DAT_08beecaf;
extern undefined DAT_08beecb0;
extern undefined4 DAT_08beee0c;
extern void FUN_088ec958();

void FUN_088cece0(void)
{
  FUN_088ec958(DAT_08beee0c,'\0',0x21,0);
  DAT_08beecaf = 1;
  DAT_08beecb0 = 0;
  return;
}

