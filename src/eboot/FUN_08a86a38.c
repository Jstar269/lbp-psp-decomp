/* LBPMATCH module=EBOOT.BIN start=0x08a86a38 end=0x08a86a94 symbol=FUN_08a86a38 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_serial_owner.h"

extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a56b48();
extern void FUN_08a56ec8();

/* Serialises the object: tag 0x534e4553 (bytes "SENS" in memory order), its two parts, then a closing call. */
void FUN_08a86a38(struct Rd4cSerialOwner *self, void *stream)
{
  FUN_08a34774(self, stream, 0x534e4553);
  FUN_08a56ec8(self->part_bc, stream, self);
  FUN_08a56b48(self->part_250, stream, self);
  FUN_0895541c(stream);
}
