/* LBPMATCH module=EBOOT.BIN start=0x08a70db4 end=0x08a70e38 symbol=FUN_08a70db4 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
/* Object with a table of virtual functions at its first word; slot 0x94/4 = 37 returns an int. */
struct VirtObj {
  int (**vtable)();
};

/* Singleton returned by FUN_08a10f1c; only field +4 is read here. */
struct Singleton {
  unsigned int unk_00;
  int tracked_value;   /* +4 */
};

extern struct Singleton *FUN_08a10f1c();
extern void FUN_08a10f98();
extern void FUN_08a346e0();

/* Re-registers the singleton with the object's virtual slot-37 value when it differs from the
   one stored at +4, then calls FUN_08a346e0 with the flag. */
void FUN_08a70db4(struct VirtObj *self, unsigned char flag)
{
  int value;
  struct Singleton *singleton;

  value = (*self->vtable[0x94 / 4])();
  singleton = FUN_08a10f1c();
  if (value != singleton->tracked_value) {
    singleton = FUN_08a10f1c();
    value = (*self->vtable[0x94 / 4])(self);
    FUN_08a10f98(singleton, value);
  }
  FUN_08a346e0(self, flag);
}
