/* LBPMATCH module=EBOOT.BIN start=0x089bbd8c end=0x089bbe34 symbol=FUN_089bbd8c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp8e, Codex GPT-6): restored stack references and second call argument; exact match verified; names and types await human review. */
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

extern void FUN_08970b6c();
extern void FUN_089745b8();

void FUN_089bbd8c(int *param_1,int *param_2)
{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 *local_20;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)*param_2;
  pcVar2 = *(code **)(*param_1 + 0x18);
  if (local_1c != (undefined4 *)0x0) {
    *(short *)((int)local_1c + 6) = *(short *)((int)local_1c + 6) + 1;
  }
  (*pcVar2)(param_1,&local_1c);
  if (local_1c != (undefined4 *)0x0) {
    FUN_08970b6c(local_1c);
  }
  local_20 = (undefined4 *)*param_2;
  puVar1 = local_20;
  if (puVar1 != (undefined4 *)0x0) {
    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + 1;
  }
  FUN_089745b8(param_1, &local_20);
  if (local_20 != (undefined4 *)0x0) {
    FUN_08970b6c(local_20);
  }
  return;
}





