/* LBPMATCH module=EBOOT.BIN start=0x08a3c10c end=0x08a3c1c8 symbol=FUN_08a3c10c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3b, Claude Sonnet 5.5): see trailing notes; NOT exact. */
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

extern undefined4 DAT_08bf03b8;
extern undefined DAT_08bf6c58;
extern int * DAT_08bf6c80;
extern int * DAT_08bf6c84;
extern void FUN_0896f07c();
extern int FUN_08a3b778();
extern undefined4 FUN_08a50fbc();
extern void FUN_08a52140();

void FUN_08a3c10c(void)
{
  int iVar1;
  int iVar2;
  
  DAT_08bf6c58 = 0;
  iVar1 = FUN_08a50fbc();
  iVar2 = FUN_08a3b778(2);
  FUN_08a52140(iVar1,*(int *)(iVar2 + 4));
  FUN_0896f07c(DAT_08bf03b8,1,(int)DAT_08bf6c84);
  if (DAT_08bf6c84 != (int *)0x0) {
    (**(code **)(*DAT_08bf6c84 + 4))(DAT_08bf6c84);
  }
  DAT_08bf6c84 = (int *)0x0;
  FUN_0896f07c(DAT_08bf03b8,1,(int)DAT_08bf6c80);
  if (DAT_08bf6c80 != (int *)0x0) {
    (**(code **)(*DAT_08bf6c80 + 4))(DAT_08bf6c80);
  }
  DAT_08bf6c80 = (int *)0x0;
  return;
}
// NEAR 4 words: gcc404xs-Os, sb on DAT_08bf6c58 and virtual calls with the object applied: the function pointer of both release calls is in v1 in retail (lw v1,4(v0); jalr v1), ours v0. At O2 the same pair becomes v0/v0 but 12 words differ.
// near miss from lane lbp3b (unreviewed)
