/* LBPMATCH module=EBOOT.BIN start=0x088edab8 end=0x088edbe8 symbol=FUN_088edab8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4c, Claude Sonnet 5.5): third argument of FUN_0889d3a4 read as piVar4[1] (the registers then follow retail); exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be85fc;
extern undefined4 DAT_08bf03b8;
extern int FUN_0889d3a4();
extern void FUN_0889d408();
extern void FUN_0889e4c8();
extern void FUN_088cc71c();
extern undefined4 FUN_0896f06c();
extern undefined * FUN_08970dbc();
extern undefined4 FUN_08974aa4();
extern void FUN_0897633c();
extern void FUN_089d1dfc();
extern void FUN_089d299c();
extern void FUN_089d856c();
extern void FUN_089d8814();
extern uint FUN_08adbd60();

void FUN_088edab8(int param_1)
{
  int iVar1;
  short *psVar2;
  int iVar3;
  int *piVar4;
  int aiStack_34 [5];
  undefined4 auStack_3c [2];
  uint local_40;
  
  piVar4 = (int *)(param_1 + 0x28c);
  iVar1 = FUN_0896f06c(DAT_08bf03b8);
  iVar1 = FUN_08974aa4(iVar1,0x4a);
  iVar1 = *(int *)(iVar1 + 0x14);
  iVar3 = *(int *)((0x12 - *(short *)(iVar1 + 0x34)) * 4 + *(int *)(iVar1 + 0x30));
  iVar1 = *(int *)((5 - *(short *)(iVar1 + 0x7c)) * 4 + *(int *)(iVar1 + 0x78));
  psVar2 = (short *)FUN_08970dbc(DAT_08be85fc,0x36b);
  FUN_0897633c(auStack_3c,psVar2);
  FUN_089d1dfc(iVar3,auStack_3c,'\0');
  FUN_088cc71c(aiStack_34);
  FUN_089d299c(iVar3,0xa0,0,'\0');
  FUN_089d8814(iVar1);
  FUN_089d856c(iVar1,3);
  FUN_0889d3a4((int)piVar4,*(int *)(param_1 + 0x28c),piVar4[1]);
  FUN_0889d408(piVar4,4);
  local_40 = FUN_08adbd60((byte *)0x0);
  FUN_0889e4c8(piVar4,4,&local_40);
  return;
}
