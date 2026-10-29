/* LBPMATCH module=EBOOT.BIN start=0x088cfcec end=0x088cfd90 symbol=FUN_088cfcec lang=c99 */
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

extern undefined DAT_088cfcec;
extern undefined * DAT_08beed14;
extern undefined * DAT_08beed8c;
extern undefined4 DAT_08beee0c;
extern void FUN_088d536c();
extern void FUN_088d7fc4();
extern undefined4 FUN_088e77d0();

void FUN_088cfcec(void)
{
  int iVar1;
  uint *puVar2;
  
  iVar1 = FUN_088e77d0(DAT_08beee0c,(int)&DAT_088cfcec);
  if ((((iVar1 == 0) && (*(ushort *)(DAT_08beed14 + 0x254) != 0xffff)) &&
      (iVar1 = *(int *)(DAT_08beed14 + 0x150) + (uint)*(ushort *)(DAT_08beed14 + 0x254) * 0x28,
      iVar1 != 0)) && (puVar2 = *(uint **)(iVar1 + 8), puVar2 != (uint *)0x0)) {
    FUN_088d536c(puVar2);
    iVar1 = DAT_08beed14;
    *(undefined1 *)(DAT_08beed8c + 0x54) = 1;
    FUN_088d7fc4(iVar1);
    return;
  }
  return;
}

// Initial primary-profile candidate: 31 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
