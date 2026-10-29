/* LBPMATCH module=EBOOT.BIN start=0x08998474 end=0x08998604 symbol=FUN_08998474 lang=c99 */
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

extern undefined * DAT_08be8480;
extern void FUN_08965dec();
extern undefined4 FUN_08974aa4();
extern void FUN_08996fec();
extern void FUN_08997cbc();
extern void FUN_08997f98();
extern void FUN_089981e4();
extern void FUN_0899832c();
extern void FUN_089d3a94();

void FUN_08998474(int param_1,uchar param_2)
{
  int iVar1;
  
  if ((DAT_08be8480 != 0) && (*(uchar *)(DAT_08be8480 + 4) != '\0')) {
    iVar1 = FUN_08974aa4(param_1,1);
    iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x14) + 0x28) +
                    *(short *)(*(int *)(iVar1 + 0x14) + 0x2c) * -4);
    FUN_08996fec(param_1,iVar1);
    FUN_08965dec(iVar1);
    iVar1 = FUN_08974aa4(param_1,9);
    FUN_08965dec(*(int *)((4 - *(short *)(*(int *)(iVar1 + 0x14) + 0x2c)) * 4 +
                         *(int *)(*(int *)(iVar1 + 0x14) + 0x28)));
    FUN_08997f98(param_1);
    FUN_089981e4(param_1);
    FUN_0899832c(param_1);
    iVar1 = FUN_08974aa4(param_1,9);
    FUN_08965dec(*(int *)((6 - *(short *)(*(int *)(iVar1 + 0x14) + 0x2c)) * 4 +
                         *(int *)(*(int *)(iVar1 + 0x14) + 0x28)));
    iVar1 = FUN_08974aa4(param_1,10);
    iVar1 = *(int *)((0xe - *(short *)(*(int *)(iVar1 + 0x14) + 0x2c)) * 4 +
                    *(int *)(*(int *)(iVar1 + 0x14) + 0x28));
    FUN_08965dec(iVar1);
    FUN_089d3a94(iVar1,1,2);
    iVar1 = FUN_08974aa4(param_1,10);
    FUN_08965dec(*(int *)((0xd - *(short *)(*(int *)(iVar1 + 0x14) + 0x2c)) * 4 +
                         *(int *)(*(int *)(iVar1 + 0x14) + 0x28)));
    return;
  }
  if (param_2 != '\0') {
    FUN_08997cbc(param_1);
  }
  FUN_08997f98(param_1);
  return;
}
// only the tail layout differs: retail places the 'if(param_2) FUN_08997cbc' test block after the f98 block (entry branch goes to a trailing test, j back, 2 extra words)
//  ours places it inline after the main body
//  tried else-if/else/early-return forms and O2 (92 words)
// near miss from lane lbp3d (unreviewed)
