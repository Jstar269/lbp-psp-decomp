/* LBPMATCH module=EBOOT.BIN start=0x089d9c68 end=0x089d9ce0 symbol=FUN_089d9c68 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): the short at +0xe is read with lh (signed) in retail, so both comparisons use a signed short instead of the translation's unsigned one; exact match verified; names and types await human review. */
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

extern void FUN_089de1e0();

void FUN_089d9c68(int param_1)
{
  if ((*(int *)(param_1 + 0x18) != param_1 + 0x18) && (*(int *)(param_1 + 0x20) != param_1 + 0x18))
  {
    FUN_089de1e0(param_1,2,
                 *(short *)(*(int *)(param_1 + 0x20) + 0xe) != (short)*(byte *)(param_1 + 0xa6));
    FUN_089de1e0(param_1,3,
                 *(short *)(*(int *)(param_1 + 0x20) + 0xe) != (short)*(byte *)(param_1 + 0xa5));
    return;
  }
  return;
}
