/* LBPMATCH module=EBOOT.BIN start=0x08a70d0c end=0x08a70db4 symbol=FUN_08a70d0c lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int * FUN_08a10f1c();
extern unsigned char FUN_08a10f68();
extern int FUN_08a34688();

typedef struct Obj70d0c Obj70d0c;
typedef struct Obj70d0cVtable {
  void *slots_00[37];
  int (*slot_94)(Obj70d0c *self);   /* result is compared with FUN_08a10f1c()[1] and handed to FUN_08a10f68 */
} Obj70d0cVtable;
struct Obj70d0c {
  Obj70d0cVtable *vtable;
};

unsigned char FUN_08a70d0c(Obj70d0c *self, unsigned char flag)
{
  unsigned char ok;
  int value;
  int *state;

  value = FUN_08a34688(self,flag);
  ok = 0;
  if (value != 0) {
    value = (*self->vtable->slot_94)(self);
    state = FUN_08a10f1c();
    ok = 1;
    if (value != state[1]) {
      state = FUN_08a10f1c();
      value = (*self->vtable->slot_94)(self);
      ok = FUN_08a10f68((int)state,value);
      return ok;
    }
  }
  return ok;
}
