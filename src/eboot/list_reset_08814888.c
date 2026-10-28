/* LBPMATCH module=EBOOT.BIN start=0x08814888 end=0x0881493c symbol=FUN_08814888 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2a, Codex GPT-6): use the list head for both reset stores and reverse their source order; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08805edc();
extern void FUN_0880610c();
extern void FUN_08814734();
extern void FUN_08adbc24();

void FUN_08814888(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if ((puVar1 != (undefined4 *)0x0) && (*(uchar *)(puVar1 + 0x1c) == '\0')) {
    FUN_08814734(puVar1,'\x01','\x01');
    *(undefined4 *)(param_1 + 0x1a0) = 9;
    puVar3 = (undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x19c) = 3;
    *(undefined4 *)(param_1 + 0x1b0) = 4;
    puVar1 = *(undefined4 **)(param_1 + 0x30);
    while (puVar1 != puVar3) {
      puVar2 = (undefined4 *)*puVar1;
      FUN_08adbc24(DAT_08be84a0,(uint)puVar1,0xc);
      puVar1 = puVar2;
    }
    *puVar3 = (undefined4)puVar3;
    ((undefined4 **)puVar3)[1] = puVar3;
    FUN_0880610c(param_1 + 0x18);
    FUN_08805edc(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x1e4) = 10;
  }
  return;
}





