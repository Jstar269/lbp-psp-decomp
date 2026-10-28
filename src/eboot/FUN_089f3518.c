/* LBPMATCH module=EBOOT.BIN start=0x089f3518 end=0x089f356c symbol=FUN_089f3518 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Brackets a call with FUN_089f1a64 / FUN_089f19c0 on id 0x1a: stores FUN_08a9e4a4(arg, 0, 0) in the field at
   +0xcc of `dest` and returns it. */
#define SCOPE_ID 0x1a

struct Destcc {
  char pad[0xcc];
  int value;                 /* +0xcc */
};

extern unsigned int FUN_089f19c0();
extern void FUN_089f1a64();
extern int FUN_08a9e4a4();

unsigned int FUN_089f3518(unsigned int unused, unsigned int arg, struct Destcc *dest)
{
  int value;

  FUN_089f1a64(SCOPE_ID);
  value = FUN_08a9e4a4(arg, 0, 0);
  dest->value = value;
  FUN_089f19c0(SCOPE_ID);
  return dest->value;
}
