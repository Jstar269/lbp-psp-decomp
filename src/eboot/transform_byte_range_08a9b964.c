/* LBPMATCH module=EBOOT.BIN start=0x08a9b964 end=0x08a9b9ac symbol=FUN_08a9b964 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): modelled the +8 begin/end pointer pair as a sub-struct address; exact match verified; names and types await human review. */
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

extern int FUN_08ba2b1c();

struct ByteRange { byte *begin; byte *end; };
struct Holder { int pad0; int pad1; struct ByteRange range; };

void FUN_08a9b964(struct Holder *param_1)
{
  int iVar1;
  byte *pbVar2;
  struct ByteRange *r = &param_1->range;
  
  for (pbVar2 = r->begin; pbVar2 != r->end; pbVar2 = pbVar2 + 1) {

    iVar1 = FUN_08ba2b1c((uint)*pbVar2);
    *pbVar2 = (byte)iVar1;
  }
  return;
}
