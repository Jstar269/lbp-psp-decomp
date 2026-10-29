/* LBPMATCH module=EBOOT.BIN start=0x08a4c918 end=0x08a4c998 symbol=FUN_08a4c918 lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): built with cc=gcc404xs-O2, typed the two objects as structs and reloaded the inner pointer after the calls; exact match verified; names and types await human review. */
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

extern void FUN_088050b8();
extern void FUN_08a4ba1c();
extern void FUN_08a4c794();
extern void FUN_08a9df6c();

struct D { char pad[0x2c]; void *a; int pad2; int b; };
struct W { struct D *d; };
struct X { char pad[0x210]; int *c; };
void FUN_08a4c918(struct W *w, struct X *x)
{
  struct D *d = w->d;
  if (d->a != 0) FUN_08a9df6c(d->a);
  int *p = x->c;
  x->c = 0;
  if (p != 0) FUN_088050b8(p);
  d = w->d;
  if (d->b != 0) { FUN_08a4c794(x); return; }
  FUN_08a4ba1c(x);
}
