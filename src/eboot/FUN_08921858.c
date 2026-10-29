/* LBPMATCH module=EBOOT.BIN start=0x08921858 end=0x089218b4 symbol=FUN_08921858 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): rewrote the goto as plain if/else on a struct and wrote the four trailing clears in field order (+4, +8, +0xc, +0x10); exact match verified; names and types await human review. */
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

extern void FUN_08a9df6c();

struct S { int a; void *ptr; int c; int d; int e; int f; void (*del)(void *); };
void FUN_08921858(struct S *s)
{
  void *p = s->ptr;
  if (p != 0) {
    if (s->del != 0) {
      s->del(p);
    } else {
      FUN_08a9df6c(p);
    }
  }
  s->ptr = 0;
  s->c = 0;
  s->d = 0;
  s->e = 0;
}
