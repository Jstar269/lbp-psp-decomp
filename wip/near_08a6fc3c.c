/* LBPMATCH module=EBOOT.BIN start=0x08a6fc3c end=0x08a6fc98 symbol=FUN_08a6fc3c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 2 word(s) differ; names and types await human review. */
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

extern undefined * DAT_08be8480;
extern void FUN_08a348ac(float param_1,int *param_2);

void FUN_08a6fc3c(float param_1,int *param_2)
{
  if ((DAT_08be8480 == 0) || (*(uchar *)(DAT_08be8480 + 0x18) == '\0')) {
    (**(void (**)(int *))(*param_2 + 0x118))(param_2);
  }
  FUN_08a348ac(param_1,param_2);
  return;
}
// differs: virtual-call fn pointer register (retail lw v1,280(v0); jalr v1 - ours reuses v0)
// tried: explicit this argument, byte-pointer global, int-cast vtable (3 variants); same class as 0x08a26bec
// near miss from lane lbp3a (unreviewed)
