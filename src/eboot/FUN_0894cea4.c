/* LBPMATCH module=EBOOT.BIN start=0x0894cea4 end=0x0894cf2c symbol=FUN_0894cea4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
/* Object with a table of virtual functions; the slots used here are 12 (+0x30), 13 (+0x34),
   14 (+0x38) and 15 (+0x3c). Their meaning is not established. */
struct VSlotObj {
  int (**vtable)();
  unsigned char unk_04[0x2c];
  int unk_30;                    /* +0x30: passed by address to slot 15 */
};

/* Runs slots 15, 13 and 14 on an id; when id is 0 it is first obtained from slot 12. Returns the id. */
int FUN_0894cea4(struct VSlotObj *self, int id)
{
  if (id == 0) {
    id = (*self->vtable[0x30 / 4])();
  }
  (*self->vtable[0x3c / 4])(self, id, &self->unk_30);
  (*self->vtable[0x34 / 4])(self, id);
  (*self->vtable[0x38 / 4])(self, id);
  return id;
}
