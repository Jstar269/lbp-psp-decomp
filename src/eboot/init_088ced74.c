/* LBPMATCH module=EBOOT.BIN start=0x088ced74 end=0x088cee08 symbol=FUN_088ced74 lang=c99 rodata=0x08bb4350 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): reference the function by symbol; exact match verified; names and types await human review. */
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

extern undefined DAT_08beeca9;
extern undefined4 DAT_08beee0c;
extern void FUN_088b5468();
extern undefined4 FUN_088d7f9c();
extern undefined4 FUN_088f5010();
extern void FUN_088f73dc();
extern void FUN_08a9bff8();
extern void FUN_08a9c0b4();
extern void FUN_08a9c164();
extern void FUN_08aaa9a0();

void FUN_088ced74(void)
{
  int iVar1;
  int aiStack_40 [6];
  int aiStack_28 [6];
  
  iVar1 = FUN_088f5010(DAT_08beee0c,(int)&FUN_088ced74);
  if (iVar1 == 0) {
    iVar1 = FUN_088d7f9c();
    FUN_088f73dc(iVar1);
    FUN_08a9c164(aiStack_28,(uint *)"levels/pod/podlevel.level.biff");
    FUN_08aaa9a0(aiStack_28);
    DAT_08beeca9 = 1;
    FUN_08a9c0b4(aiStack_40,(int)aiStack_28);
    FUN_088b5468(aiStack_40);
    FUN_08a9bff8((int)aiStack_40);
    FUN_08a9bff8((int)aiStack_28);
  }
  return;
}



