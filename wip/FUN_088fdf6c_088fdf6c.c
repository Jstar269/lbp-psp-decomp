/* LBPMATCH module=EBOOT.BIN start=0x088fdf6c end=0x088fe028 symbol=FUN_088fdf6c lang=c99 cc=gcc404xs-Os rodata=0x08bab5e8 */
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

extern int DAT_08bf7304;
extern void FUN_088f9504();
extern void FUN_0891074c();
extern void FUN_08a2f7f8(float param_1,int param_2,int *param_3,char param_4);
extern undefined4 FUN_08a50fbc();

void FUN_088fdf6c(int param_1)
{
  int iVar1;
  float fVar2;
  int *local_20 [4];
  
  FUN_0891074c(param_1);
  FUN_08a50fbc();
  iVar1 = DAT_08bf7304;
  FUN_088f9504((undefined4 *)(param_1 + 0x1c),8);
  fVar2 = 0.0f;
  if (*(int *)(iVar1 + 0x8ec) - 0xbU < 2) {
    fVar2 = 0.2f;
  }
  local_20[0] = *(int **)(param_1 + 0x58);
  iVar1 = *(int *)(iVar1 + 0x24c);
  if (local_20[0] != (int *)0x0) {
    local_20[0][1] = local_20[0][1] + 1;
  }
  FUN_08a2f7f8(fVar2,iVar1,(int *)local_20,'\0');
  if ((local_20[0] != (int *)0x0) &&
     (iVar1 = local_20[0][1], local_20[0][1] = iVar1 + -1, iVar1 + -1 == 0)) {
    (**(code **)(*local_20[0] + 8))(local_20[0]);
  }
  return;
}

// best of the profile sweep: cc=gcc404xs-Os, 22 differing words left of 47.
// near miss from lane lbp2c (unreviewed)
