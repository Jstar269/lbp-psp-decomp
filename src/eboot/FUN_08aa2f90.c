/* LBPMATCH module=EBOOT.BIN start=0x08aa2f90 end=0x08aa2fe8 symbol=FUN_08aa2f90 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd1b, Claude Sonnet) */

#include "lbp/pixsurface.h"

/* Fill a width x height block of 16-bit pixels, starting at row `row` (column 0), with `color`. */
void FUN_08aa2f90(PixSurface *surface, int unused_1, int row, int width, int height, unsigned short color)
{
  int stride;
  int x;
  unsigned short *dst;
  int y;

  if (width != 0 || height != 0) {
    stride = surface->stride;
    y = 0;
    dst = (unsigned short *)(surface->pixels + stride * row * 2);
    do {
      x = 0;
      do {
        x = x + 1;
        *dst = color;
        dst = dst + 1;
      } while (x != width);
      y = y + 1;
      dst = dst + (stride - width);   /* skip to the start of the next row */
    } while (y != height);
  }
  return;
}
