/* LBPMATCH module=EBOOT.BIN start=0x08aa2fe8 end=0x08aa3040 symbol=FUN_08aa2fe8 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */
#include "lbp/pixsurface.h"

/* Fill the whole surface (width x height pixels, 16 bits each) with `color`. */
void FUN_08aa2fe8(PixSurface *surface, unsigned short color)
{
  unsigned short *dst;
  int x;
  unsigned int y;
  int width;
  unsigned int height;

  height = surface->height;
  for (y = 0; y < height; y = y + 1) {
    width = surface->width;
    dst = (unsigned short *)(surface->pixels + surface->stride * y * 2);
    for (x = 0; x != width; x = x + 1) {
      *dst = color;
      dst = dst + 1;
    }
  }
  return;
}
