/* LBPMATCH module=EBOOT.BIN start=0x08a4d370 end=0x08a4d504 symbol=FUN_08a4d370 lang=c99 */
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

extern undefined4 DAT_08be8600;
extern void FUN_088050b8();
extern void FUN_088bb890();
extern void FUN_08921a38();
extern void FUN_089e7130();
extern undefined4 FUN_08a50fbc();
extern void FUN_08a537dc();
extern void FUN_08a6dab8();
extern void FUN_08a9e0cc();
extern undefined4 FUN_08af72b0();
extern undefined4 FUN_08af7480();
extern undefined4 FUN_08af767c();
extern uint * FUN_08ba0c84();
extern int FUN_08ba0e8c();
extern char * FUN_08ba10e8();

void FUN_08a4d370(int param_1)
{
  uint *puVar1;
  int iVar2;
  uint auStack_88 [26];
  char acStack_cc [68];
  undefined4 local_d0;
  undefined4 local_d4;
  undefined4 local_d8;
  undefined4 local_dc;
  undefined4 local_e0;
  undefined4 uStack_e4;
  undefined4 local_e8;
  undefined4 local_ec;
  undefined4 local_f0;
  undefined4 local_f4;
  undefined4 local_f8;
  undefined4 local_fc;
  undefined4 local_100;
  
  local_d8 = 0;
  local_d4 = *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x20);
  local_d0 = *(undefined4 *)(param_1 + 0x200);
  puVar1 = FUN_08ba0c84((uint *)param_1,0x2f);
  iVar2 = FUN_08ba0e8c((char *)param_1);
  FUN_08ba10e8(acStack_cc,(char *)param_1,iVar2 + 1);
  iVar2 = FUN_08ba0e8c((char *)((int)puVar1 + 1));
  FUN_08ba10e8(acStack_cc,(char *)((int)puVar1 + 1),iVar2 + 1);
  FUN_089e7130(DAT_08be8600,2,&local_d8);
  iVar2 = *(int *)(param_1 + 0x1e4);
  FUN_08af767c(auStack_88);
  FUN_08af72b0((int)auStack_88,(undefined1 *)(iVar2 + 0x40),0x14);
  FUN_08af7480(auStack_88,(undefined1 *)&local_ec);
  local_100 = local_ec;
  local_fc = local_e8;
  local_f8 = uStack_e4;
  local_f4 = local_e0;
  local_f0 = local_dc;
  FUN_08a6dab8(param_1 + 0xf0,&local_100,'\0');
  FUN_088bb890(*(int *)(param_1 + 0x218));
  iVar2 = FUN_08a50fbc();
  FUN_08a537dc(iVar2,*(uint *)(param_1 + 0x1e0));
  if (*(int **)(param_1 + 0x210) != (int *)0x0) {
    FUN_088050b8(*(int **)(param_1 + 0x210));
  }
  FUN_08921a38((undefined4 *)(param_1 + 500));
  if (*(int **)(param_1 + 0x1ec) != (int *)0x0) {
    FUN_088050b8(*(int **)(param_1 + 0x1ec));
  }
  FUN_08a9e0cc(param_1);
  return;
}
// g11 baseline: 101 words differ; stack copies and decompiler variables need reconstruction.
// near miss from lane lbp13d (unreviewed)
