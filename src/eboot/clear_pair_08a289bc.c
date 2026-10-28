/* LBPMATCH module=EBOOT.BIN start=0x08a289bc end=0x08a28a28 symbol=FUN_08a289bc lang=c99 cc=gcc171-Os */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp2b, DeepSeek through Freebuff): the two zero stores to *param_1 and param_1+0xa4 are written in the opposite order in the translation, and retail emits the byte store at offset 0 first; exact match verified; names and types await human review. */
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

extern void FUN_08a9e0c4();

void FUN_08a289bc(undefined1 *param_1)
{
  if (*(uint *)(param_1 + 8) != 0) {
    FUN_08a9e0c4(*(uint *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(uint *)(param_1 + 0xa0) != 0) {
    FUN_08a9e0c4(*(uint *)(param_1 + 0xa0));
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  if (*(uint *)(param_1 + 0xa4) != 0) {
    FUN_08a9e0c4(*(uint *)(param_1 + 0xa4));
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *param_1 = 0;
  return;
}
