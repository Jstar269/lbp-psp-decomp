/* LBPMATCH module=EBOOT.BIN start=0x088f66dc end=0x088f6778 symbol=FUN_088f66dc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp8f, Codex GPT-6): restore the receiver argument; exact match verified; names and types await human review. */
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

extern void FUN_088e66e8(param_1);
extern void FUN_088e68a0();
extern void FUN_088ea1f0();
extern undefined4 FUN_089eb734();
extern undefined * FUN_089ecaa8();

void FUN_088f66dc(int param_1)
{
  undefined *puVar1;
  
  if (*(int *)(param_1 + 0x44) == 4) {
    FUN_088ea1f0(param_1,'\0',0x42);
    if (*(int *)(param_1 + 0xa0) != 0) {
      *(undefined4 *)(param_1 + 0xa0) = 0;
    }
    FUN_088e66e8(param_1);
    if ((*(int *)(param_1 + 0x44) != 0) && (*(int *)(param_1 + 0x44) != 0x1a)) {
      *(undefined4 *)(param_1 + 0x44) = 0x1a;
      puVar1 = FUN_089ecaa8();
      FUN_089eb734((int)puVar1,0,0);
    }
    FUN_088e68a0(param_1,'\x01',0x43);
    return;
  }
  return;
}


