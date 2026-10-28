/* LBPMATCH module=EBOOT.BIN start=0x0880b178 end=0x0880b1ac symbol=FUN_0880b178 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_modeobj.h"

/* Returns 1 when the object has a target whose flag byte (+0x70) is set and its mode word is 1, else 0
   (the four sibling tests at 0x0880b178..0x0880b248 differ only in the mode). */
unsigned int FUN_0880b178(struct Rd3dModeOwner *self)
{
  unsigned int result;

  result = 0;
  if ((self->target != 0) &&
     ((result = 1, self->target->flag_70 == '\0' || (self->mode != RD3D_MODE_1)))) {
    result = 0;
  }
  return result;
}
