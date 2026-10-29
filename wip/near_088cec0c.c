/* LBPMATCH module=EBOOT.BIN start=0x088cec0c end=0x088cec68 symbol=FUN_088cec0c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 2 word(s) differ; names and types await human review. */
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

extern undefined DAT_088cec0c;
extern undefined4 DAT_08beee0c;
extern void FUN_088e66e8();
extern void FUN_088e68a0();
extern void FUN_088e8554();
extern undefined4 FUN_088f6650();

void FUN_088cec0c(void)
{
  int iVar1;
  
  iVar1 = FUN_088f6650(DAT_08beee0c,(int)&DAT_088cec0c);
  if (iVar1 != 0) {
    FUN_088e68a0(DAT_08beee0c,'\x01',0x28);
    return;
  }
  FUN_088e66e8();
  FUN_088e8554(DAT_08beee0c);
  return;
}
// differs: delay-slot/scheduling of 'li a2,40' vs the branch (retail sets a1/a2 before beqz and fills the delay slot with the lw of the global)
// tried: swapped branches, args via a local, one-statement form
// near miss from lane lbp3a (unreviewed)
