/* LBPMATCH module=EBOOT.BIN start=0x08840b50 end=0x08840c48 symbol=FUN_08840b50 lang=c99 */
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

extern undefined4 DAT_08bdb118;
extern undefined * DAT_08bedb24;
extern void FUN_088050b8();
extern void FUN_08a9e11c();
extern int FUN_08a9f058();
extern void FUN_08adbe84();

void FUN_08840b50(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    FUN_088050b8(piVar1);
  }
  if (*(int *)(param_1 + 4) != 0) {
    FUN_08a9e11c(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if ((DAT_08bdb118 >= (uint)(DAT_08bedb24 + param_3)) &&
     (puVar2 = (undefined4 *)FUN_08a9f058(param_3,0x10,0,0), puVar2 != (undefined4 *)0x0)) {
    *(undefined4 **)(param_1 + 4) = puVar2;
    *(int *)(param_1 + 8) = param_3;
    *(undefined4 *)(param_1 + 0xc) = param_4;
    DAT_08bedb24 = DAT_08bedb24 + param_3;
    FUN_08adbe84(puVar2,param_2,param_3);
    return;
  }
  return;
}
// differs: order of the stores to param_1+4/+0xc/+8 relative to the DAT reload (retail: lw DAT, sw +4, addu, sw +0xc, sw +8, sw DAT)
// tried: all 24 permutations of the four stores; '>=' form of the limit compare fixed the sltu register
// near miss from lane lbp3a (unreviewed)
