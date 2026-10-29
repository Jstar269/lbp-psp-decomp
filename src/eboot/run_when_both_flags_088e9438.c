/* LBPMATCH module=EBOOT.BIN start=0x088e9438 end=0x088e94c0 symbol=FUN_088e9438 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp3c, Claude Sonnet 5.5): replaced the shift tests with a bit-field struct read into locals; matching idiom: bit fields read into locals before the test; exact match verified; names and types await human review. */
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

extern void FUN_088e9398();
extern void FUN_089ea694();
extern void FUN_089ea758();
extern void FUN_089ea928();
extern void FUN_089ea93c();
extern undefined4 FUN_089f19c0();
extern void FUN_089f1a64();
extern void FUN_08a1bbd4();
extern undefined4 FUN_08a50fbc();
extern void FUN_08a52074();

struct Flags { unsigned lo : 17; unsigned a : 1; unsigned b : 1; unsigned rest : 13; };
void FUN_088e9438(int param_1)
{
  int iVar1;
  undefined4 auStack_f0 [56];
  
  struct Flags *f = (struct Flags *)(param_1 + 0xd0);
  uint a = f->a;
  uint b = f->b;
  if (a && b) {
    FUN_089f1a64(0xf);
    FUN_089ea928(auStack_f0);
    FUN_089ea694((int)auStack_f0);
    FUN_08a1bbd4();
    iVar1 = FUN_08a50fbc();
    FUN_08a52074(iVar1);
    FUN_088e9398(param_1 + 0x14);
    FUN_089ea758((int)auStack_f0);
    FUN_089f19c0(15);
    FUN_089ea93c(auStack_f0);
  }
  return;
}
