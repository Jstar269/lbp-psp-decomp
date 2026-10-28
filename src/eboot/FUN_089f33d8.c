/* LBPMATCH module=EBOOT.BIN start=0x089f33d8 end=0x089f342c symbol=FUN_089f33d8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Brackets a call with FUN_089f1a64 / FUN_089f19c0 on id 0x1a: stores FUN_08a9e4a4(arg, 0, 0) in the field at
   +0x48 of `dest` and returns it. */
#define SCOPE_ID 0x1a

struct Dest48 {
  char pad[0x48];
  int value;                 /* +0x48 */
};

extern unsigned int FUN_089f19c0();
extern void FUN_089f1a64();
extern int FUN_08a9e4a4();

unsigned int FUN_089f33d8(unsigned int unused, unsigned int arg, struct Dest48 *dest)
{
  int value;

  FUN_089f1a64(SCOPE_ID);
  value = FUN_08a9e4a4(arg, 0, 0);
  dest->value = value;
  FUN_089f19c0(SCOPE_ID);
  return dest->value;
}
