/* LBPMATCH module=EBOOT.BIN start=0x088d0438 end=0x088d0514 symbol=FUN_088d0438 lang=c99 */
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

extern undefined DAT_088d0438;
extern undefined * DAT_08beed14;
extern undefined4 DAT_08beee0c;
extern void FUN_088cfb84();
extern void FUN_088e68a0();
extern undefined4 FUN_088f65dc();

void FUN_088d0438(void)
{
  int iVar1;
  uint *puVar2;
  
  FUN_088e68a0(DAT_08beee0c,'\0',0x33);
  iVar1 = FUN_088f65dc(DAT_08beee0c,(int)&DAT_088d0438);
  if (iVar1 != 0) {
    return;
  }
  if (*(ushort *)(DAT_08beed14 + 0x254) == 0xffff) {
    puVar2 = (uint *)0x0;
  }
  else {
    iVar1 = *(int *)(DAT_08beed14 + 0x150) + (uint)*(ushort *)(DAT_08beed14 + 0x254) * 0x28;
    if (iVar1 == 0) {
      puVar2 = (uint *)0x0;
    }
    else {
      puVar2 = *(uint **)(iVar1 + 8);
    }
  }
  if (((((*puVar2 & 0x20) != 0) && (puVar2[0xe] != 0xffff)) && (puVar2[0xe] != 0)) &&
     ((*puVar2 & 0x7c0) == 0)) {
    FUN_088e68a0(DAT_08beee0c,'\x01',0x34);
    return;
  }
  FUN_088cfb84();
  return;
}

// 32 differing words; typed structures retain divergent index and register scheduling.
// near miss from lane lbp7a (unreviewed)
