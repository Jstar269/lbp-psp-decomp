/* LBPMATCH module=EBOOT.BIN start=0x088fed04 end=0x088fedb0 symbol=FUN_088fed04 lang=c99 cc=gcc404xs-Os rodata=0x08bab5d8 */
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

extern undefined * DAT_08bf7304;
extern void FUN_0891074c();
extern void FUN_08a2f7f8(float param_1,int param_2,int *param_3,char param_4);
extern undefined4 FUN_08a50fbc();

void FUN_088fed04(int param_1)
{
  int iVar1;
  int *apiStack_20 [4];
  
  FUN_0891074c(param_1);
  FUN_08a50fbc();
  apiStack_20[0] = *(int **)(param_1 + 0x38);
  iVar1 = *(int *)(DAT_08bf7304 + 0x24c);
  if (apiStack_20[0] != (int *)0x0) {
    apiStack_20[0][1] = apiStack_20[0][1] + 1;
  }
  FUN_08a2f7f8(0.1f,iVar1,(int *)apiStack_20,'\0');
  if ((apiStack_20[0] != (int *)0x0) &&
     (iVar1 = apiStack_20[0][1], apiStack_20[0][1] = iVar1 + -1, iVar1 + -1 == 0)) {
    (**(code **)(*apiStack_20[0] + 8))(apiStack_20[0]);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}

// profile sweep: 23 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
