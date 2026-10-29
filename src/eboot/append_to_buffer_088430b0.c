/* LBPMATCH module=EBOOT.BIN start=0x088430b0 end=0x08843144 symbol=FUN_088430b0 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): modelled the buffer as a struct with a length, capacity and data array and cached the buffer pointer after the call; exact match verified; names and types await human review. */
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

extern void FUN_08842fe4();
extern undefined4 * FUN_08b9e8cc();

struct Buf { uint len; uint cap; char data[1]; };
struct Str { struct Buf *buf; };

struct Str * FUN_088430b0(struct Str *param_1,undefined4 *param_2,int param_3)
{
  uint uVar1;
  uint uVar3;
  
  uVar1 = param_1->buf->cap;
  uVar3 = param_1->buf->len + param_3;
  if (uVar1 < uVar3) {
    FUN_08842fe4(param_1,uVar3 + uVar1);
  }
  FUN_08b9e8cc((undefined4 *)(param_1->buf->data + param_1->buf->len),param_2,param_3);
  struct Buf *b = param_1->buf;
  char *d = b->data;
  d[uVar3] = 0;
  b->len = uVar3;

  return param_1;
}

