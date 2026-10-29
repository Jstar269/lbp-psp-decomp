/* LBPMATCH module=EBOOT.BIN start=0x089633d0 end=0x08963424 symbol=FUN_089633d0 lang=c99 */
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

extern undefined4 DAT_08bf03b8;
extern undefined * DAT_08bf7304;
extern void FUN_0890c3dc(float *param_1);
extern int * FUN_0896fea8();
extern void FUN_08970b6c();
extern undefined4 FUN_08a50fbc();

void FUN_089633d0(void)
{
  undefined4 *local_20 [4];
  
  FUN_0896fea8((int *)local_20,DAT_08bf03b8,0xfa6);
  if (local_20[0] != (undefined4 *)0x0) {
    FUN_08970b6c(local_20[0]);
    FUN_08a50fbc();
    FUN_0890c3dc((float *)(DAT_08bf7304 + 800));
  }
  return;
}
// NEAR: only scheduling differs: retail puts 'lui v0' before 'sw ra' and 'li a2,4006' before the call with 'lw a1,952(v0)' in the jal delay slot; ours the reverse. Tried typed callee (struct Ref*, struct Vec*), void* out, O2 (worse).
// near miss from lane lbp4c (unreviewed)
