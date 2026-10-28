/* LBPMATCH module=EBOOT.BIN start=0x08b9b684 end=0x08b9b72c symbol=FUN_08b9b684 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g6) corrected by hand (lane lbp1c, Codex GPT-6): three-way comparison; exact match verified; names and types await human review. */
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

extern uint * FUN_08b9b37c();
extern undefined4 FUN_08b9b4b8();

undefined4 FUN_08b9b684(int param_1,int param_2,int param_3)
{
  ushort *puVar1;
  uint local_2c [3];
  uint local_30;
  
  puVar1 = (ushort *)FUN_08b9b4b8((byte)((uint)(*(int *)(param_1 + 0x10) << 0x15) >> 0x18),param_1);
  FUN_08b9b37c((*(uint *)(param_1 + 0x10) & 0x7ff) >> 3,puVar1,(ushort *)(param_2 + 8),&local_30);
  FUN_08b9b37c((*(uint *)(param_1 + 0x10) & 0x7ff) >> 3,puVar1,(ushort *)(param_3 + 8),local_2c);
  return local_30 > local_2c[0] ? 1 : (local_30 < local_2c[0] ? -1 : 0);
}



