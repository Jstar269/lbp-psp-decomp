/* LBPMATCH module=EBOOT.BIN start=0x08917a18 end=0x08917ac0 symbol=FUN_08917a18 lang=c99 */
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

extern int DAT_08bef4b0;
extern undefined4 DAT_08bef4b4;
extern undefined4 DAT_08bef4cc;
extern undefined4 DAT_08bef4d0;
extern undefined4 DAT_08bef4d8;
extern void FUN_08916e64();

void FUN_08917a18(void)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_08bef4b0;
  iVar2 = 0;
  while( true ) {
    iVar3 = iVar2;
    if (DAT_08bef4d0 <= iVar3) break;
    iVar2 = iVar3 + 1;
    if (*(int *)(iVar3 * 0x10 + DAT_08bef4b4) != 0) {
      FUN_08916e64(piVar1,iVar3);
    }
  }
  if (DAT_08bef4d8 != 0) {
    (**(code **)(*piVar1 + 0xc))();
    DAT_08bef4b4 = 0;
    DAT_08bef4d8 = 0;
    DAT_08bef4cc = 0;
  }
  return;
}

// Initial primary-profile candidate: 26 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
