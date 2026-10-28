/* LBPMATCH module=EBOOT.BIN start=0x0894fbf4 end=0x0894fca4 symbol=FUN_0894fbf4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int FUN_08adb0e0();
extern unsigned int FUN_08adb104();

typedef struct Obj894fbf4 Obj894fbf4;
typedef struct Obj894fbf4Vtable {
  void *slots_00[8];
  int (*slot_20)(Obj894fbf4 *self);
  int (*slot_24)(Obj894fbf4 *self);
} Obj894fbf4Vtable;
struct Obj894fbf4 {
  Obj894fbf4Vtable *vtable;
};

void FUN_0894fbf4(Obj894fbf4 *self, void *arg_b, unsigned int arg_c, int arg_d, int arg_e)
{
  int slot20_result;
  int slot24_result;
  unsigned int slot20_again;

  slot20_result = (*self->vtable->slot_20)(self);
  slot24_result = (*self->vtable->slot_24)(self);
  slot20_result = FUN_08adb0e0(slot20_result,slot24_result,arg_d);
  slot20_again = (*self->vtable->slot_20)(self);
  FUN_08adb104(slot20_result,arg_b,slot20_again,arg_c,arg_e);
  return;
}
