/* LBPMATCH module=EBOOT.BIN start=0x0894a49c end=0x0894a4e4 symbol=FUN_0894a49c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): pass the local object to cleanup; exact match verified; names and types await human review. */
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

extern undefined4 FUN_08ad27d0();
extern undefined4 FUN_08ad27f4();
extern undefined4 FUN_08ad2a70();
extern undefined4 FUN_08ad2b0c();

void FUN_0894a49c(int *param_1)
{
  undefined4 auStack_20 [4];
  
  FUN_08ad27d0(auStack_20);
  FUN_08ad27f4((int)auStack_20,2);
  FUN_08ad2b0c(param_1,auStack_20);
  FUN_08ad2a70(auStack_20);
  return;
}


