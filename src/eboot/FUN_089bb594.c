/* LBPMATCH module=EBOOT.BIN start=0x089bb594 end=0x089bb62c symbol=FUN_089bb594 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): typed with structs (guard object with two index/array pairs) and merged the duplicated branches into one condition; exact match verified; names and types await human review. */
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

extern undefined DAT_08beecad;
extern undefined DAT_08beecae;
extern int FUN_089afe98();

struct Ob { int a; uint flags; };
struct G { char pad[0x78]; int *arr1; short i1; char pad2[0x22]; struct Ob **arr2; short i2; };
struct T { char pad[0x14]; struct G *g; };
void FUN_089bb594(struct T *t,uchar param_2)
{
  FUN_089afe98(param_2, t->g, t->g->arr1[2 - t->g->i1]);
  if (DAT_08beecad != '\0' || DAT_08beecae != '\0') {
    struct Ob *o = t->g->arr2[7 - t->g->i2];
    o->flags |= 0x400;
  }
}
