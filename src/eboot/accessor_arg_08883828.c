/* LBPMATCH module=EBOOT.BIN start=0x08883828 end=0x08883898 symbol=FUN_08883828 lang=c99 cc=gcc404xs-Os */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): retail feeds the value FUN_089ecaa8 returns into the next accessor as its first argument (move a0,v0 in the jal delay slot), which the translation had dropped; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08bdb1f4;
extern undefined4 DAT_08bdb1f8;
extern undefined DAT_08bdb1fc;
extern undefined4 DAT_08bee030;
extern void FUN_08882470();
extern void FUN_08889aa8();
extern undefined4 FUN_089ea984(undefined *param_1);
extern undefined4 FUN_089ea98c(undefined *param_1);
extern undefined * FUN_089ecaa8();

void FUN_08883828(void)
{
  FUN_08889aa8(DAT_08bee030);
  FUN_08882470();
  if (DAT_08bdb1fc != '\0') {
    DAT_08bdb1f8 = FUN_089ea984(FUN_089ecaa8());
    DAT_08bdb1f4 = FUN_089ea98c(FUN_089ecaa8());
    DAT_08bdb1fc = '\0';
  }
  return;
}
