/* LBPMATCH module=EBOOT.BIN start=0x0891d7d8 end=0x0891d830 symbol=FUN_0891d7d8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd4a_ownedcell.h"

extern void FUN_08a9df6c();
extern void FUN_08a9e0cc();

void FUN_0891d7d8(struct CellOwner *self)
{
  struct HandleCell *cell;

  cell = self->cell;
  if (cell != (struct HandleCell *)0x0) {
    if (cell->handle != 0) {
      FUN_08a9df6c(cell->handle);
      cell->handle = 0;
    }
    cell->unk_04 = 0;
    FUN_08a9e0cc(cell);
    self->cell = 0;
  }
  return;
}
