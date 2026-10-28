/* LBPMATCH module=EBOOT.BIN start=0x08aa2dec end=0x08aa2e44 symbol=FUN_08aa2dec lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review; readability pass (lane rd1b, Claude Sonnet) */
#include "lbp/pixsurface.h"

/* Fill a width x height block of 32-bit pixels, starting at row `row` (column 0), with `color`. */
void FUN_08aa2dec(PixSurface *surface, int unused_1, int row, int width, int height, unsigned int color)
{
  int x;
  unsigned int *dst;
  int y;

  y = 0;
  if (width != 0 || height != 0) {
    dst = (unsigned int *)(surface->pixels + surface->stride * row * 4);
    do {
      x = 0;
      do {
        x = x + 1;
        *dst = color;
        dst = dst + 1;
      } while (x != width);
      y = y + 1;
      dst = dst + (surface->stride - width);   /* skip to the start of the next row */
    } while (y != height);
  }
  return;
}
