/* LBPMATCH module=EBOOT.BIN start=0x0881aafc end=0x0881ab68 symbol=FUN_0881aafc lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp3c, Claude Sonnet 5.5): reordered the independent stores to the order retail emits; exact match verified; names and types await human review. */
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

extern void FUN_08814734();
extern void FUN_08819a40();

void FUN_0881aafc(int param_1)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if ((puVar1 != (undefined4 *)0x0) && (*(uchar *)(puVar1 + 0x1c) == '\0')) {
    FUN_08814734(puVar1,'\x01','\x01');
    *(undefined4 *)(param_1 + 0x19c) = 3;
    *(undefined4 *)(param_1 + 0x1a0) = 4;
    *(undefined4 *)(param_1 + 0x1b0) = 4;
    FUN_08819a40(param_1);
    *(undefined4 *)(param_1 + 0x1e4) = 3;
  }
  return;
}
