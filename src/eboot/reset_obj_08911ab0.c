/* LBPMATCH module=EBOOT.BIN start=0x08911ab0 end=0x08911afc symbol=FUN_08911ab0 lang=c99 rodata=0x08bac1b4 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp4d, Claude Sonnet 5.5): struct field access, float 2.0f field store, global read into a local before the stores; exact match verified; names and types await human review. */
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
typedef float undefined4;
extern int DAT_08bf7304;
extern void FUN_0890adc4(void *, int);
extern void FUN_0891074c(void *);
extern int FUN_08a50fbc();
struct Obj { char pad[0x18]; int a; int pad2; float f; };
void FUN_08911ab0(struct Obj *o)
{
  int base;
  FUN_0891074c(o);
  FUN_08a50fbc();
  base = DAT_08bf7304;
  o->a = 0;
  o->f = 2.0f;
  FUN_0890adc4((char *)base + 0x400, 0);
}

