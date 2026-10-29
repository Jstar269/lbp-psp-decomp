/* LBPMATCH module=EBOOT.BIN start=0x0894d1c4 end=0x0894d220 symbol=FUN_0894d1c4 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): typed the object as a struct with an embedded sub-object whose vtable slot 0x38 is called, magic constant stored as uint, dropped the generated rodata= key; exact match verified; names and types await human review. */
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

extern uint * FUN_0894b31c();
extern void FUN_0894b3e4();

struct Sub { struct V *vt; };
struct O { int a; struct Sub sub; };
struct V { char pad[0x38]; void (*f)(struct Sub *, uint *); };
void FUN_0894d1c4(struct O *o, undefined4 *param_2)
{
  uint *puVar1 = FUN_0894b31c(param_2);
  void (*pcVar2)(struct Sub *, uint *) = o->sub.vt->f;
  puVar1[1] = 0x54584554;
  pcVar2(&o->sub, puVar1);
  FUN_0894b3e4(puVar1,4);
}
