/* LBPMATCH module=EBOOT.BIN start=0x08902040 end=0x0890211c symbol=FUN_08902040 lang=c99 */
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

extern int DAT_08be8480;
extern undefined * DAT_08bf7304;
extern void FUN_0891074c();
extern void FUN_08a2f7f8(float param_1,int param_2,int *param_3,char param_4);
extern undefined4 FUN_08a50fbc();
extern void FUN_08a78154();

void FUN_08902040(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  int *local_20 [4];
  
  FUN_0891074c(param_1);
  FUN_08a50fbc();
  iVar2 = DAT_08bf7304;
  iVar3 = **(int **)(param_1 + 0x1c);
  *(undefined1 *)(DAT_08bf7304 + 0x96) = 0;
  pcVar4 = *(code **)(iVar3 + 0x18);
  *(undefined1 *)(param_1 + 0x18) = 0;
  (*pcVar4)(0);
  local_20[0] = *(int **)(param_1 + 0x1c);
  iVar3 = *(int *)(iVar2 + 0x24c);
  if (local_20[0] != (int *)0x0) {
    local_20[0][1] = local_20[0][1] + 1;
  }
  FUN_08a2f7f8(0.0f,iVar3,(int *)local_20,'\0');
  if ((local_20[0] != (int *)0x0) &&
     (iVar3 = local_20[0][1], local_20[0][1] = iVar3 + -1, iVar3 + -1 == 0)) {
    (**(code **)(*local_20[0] + 8))(local_20[0]);
  }
  iVar3 = DAT_08be8480;
  bVar1 = DAT_08be8480 != 0;
  *(undefined1 *)(iVar2 + 0x354) = 1;
  if ((bVar1) && (*(char *)(iVar3 + 4) != '\0')) {
    FUN_08a78154(iVar2);
  }
  return;
}

// 31 words differ: virtual float call and scheduling; C++ reconstruction produced larger mismatch.
// near miss from lane lbp7a (unreviewed)
