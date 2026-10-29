/* LBPMATCH module=EBOOT.BIN start=0x088c8f48 end=0x088c9030 symbol=FUN_088c8f48 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 5 word(s) differ; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern void FUN_088050b8();
extern void FUN_088bcb3c();
extern void FUN_088c8e1c();
extern void FUN_08adbc24();
extern void FUN_08b88fc8();
extern void FUN_088c6010();
extern void FUN_088c69bc();
extern void FUN_0894ebcc();

void FUN_088c8f48(int param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + 0x58);
  FUN_088bcb3c(param_1 + 0x90);
  *(undefined4 *)(param_1 + 0xb0) = 0;
  FUN_088c8e1c(param_1);
  if (*(undefined4 **)(param_1 + 0x58) != puVar3) {
    puVar1 = (undefined4 *)*puVar3;
    while (puVar1 != puVar3) {
      (**(code **)(**(int **)(puVar1[2] + 0xa8) + 0x28))
                (*(int **)(puVar1[2] + 0xa8),0,0,FUN_088c69bc,param_1,FUN_088c6010,FUN_0894ebcc);
      FUN_088bcb3c(param_1 + 0x90);
      piVar2 = (int *)*puVar3;
      FUN_08b88fc8(piVar2);
      if ((int *)piVar2[2] != (int *)0x0) {
        FUN_088050b8((int *)piVar2[2]);
      }
      FUN_08adbc24(DAT_08be84a0,(uint)piVar2,0xc);
      puVar1 = (undefined4 *)*puVar3;
    }
  }
  return;
}
// differs: loop-entry shape (retail: bnel with 'lw v0,0(s2)' in the delay slot, loop var in v0; ours bne + move v1,v0, CSE of the first list-head load)
// tried: while-form (worse: 47), list head recomputed after the test, reloading the head from param_1+0x58 (4 variants)
// near miss from lane lbp3a (unreviewed)
