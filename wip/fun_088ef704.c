/* LBPMATCH module=EBOOT.BIN start=0x088ef704 end=0x088ef7f8 symbol=FUN_088ef704 lang=c99 */
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

extern char DAT_08beedc4;
extern undefined * DAT_08beed14;
extern undefined * DAT_08beee0c;
extern void FUN_088dfd8c();
extern int FUN_088e6e1c();
extern int FUN_088e7d14();
extern void FUN_088ef50c();
extern void FUN_08921170();
extern int FUN_08b89838();

void FUN_088ef704(uint *param_1)
{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  uint uStack_20;
  uint *puStack_1c;
  int iStack_18;
  int iStack_14;
  
  uStack_20 = *param_1;
  iVar1 = FUN_088e6e1c(&DAT_08beedc4,&uStack_20);
  iStack_14 = FUN_088e7d14(&DAT_08beedc4,&uStack_20);
  for (iVar2 = iVar1; iVar2 != iStack_14; iVar2 = FUN_08b89838(iVar2)) {
  }
  iStack_18 = iVar1;
  FUN_088ef50c(&DAT_08beedc4,iVar1,iStack_14);
  puVar4 = (undefined4 *)(DAT_08beed14 + 0x1dc);
  *(uint *)(DAT_08beed14 + 0x1fc) = *(uint *)(DAT_08beed14 + 0x1fc) | 2;
  if (*(int *)(*param_1 + 0x34) == 0) {
    puStack_1c = *(uint **)(*param_1 + 0x2c);
    FUN_088dfd8c(puVar4,puStack_1c);
    FUN_08921170(param_1,(int *)&puStack_1c,0);
  }
  pcVar3 = *(code **)(DAT_08beee0c + 0xa8);
  if (pcVar3 != (code *)0x0) {
    *(undefined4 *)(DAT_08beee0c + 0xa8) = 0;
    (*pcVar3)();
  }
  return;
}


// Missing local iterator stores; related to 0x088effac; branch and register layout unresolved.
// near miss from lane lbp8e (unreviewed)
