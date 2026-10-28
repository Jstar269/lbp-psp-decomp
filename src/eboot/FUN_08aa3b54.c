/* LBPMATCH module=EBOOT.BIN start=0x08aa3b54 end=0x08aa3c40 symbol=FUN_08aa3b54 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

#include "lbp/grid.h"

/* Mirrors every column: swaps the cell at y with the cell at height - 1 - y for the top half of each column. */
void FUN_08aa3b54(struct Grid *grid)
{
  unsigned int first;
  unsigned int second;
  void (*set_value)(struct Grid *, unsigned int, unsigned int, unsigned int);
  unsigned int y;
  unsigned int x;

  for (x = 0; y = 0, x < (unsigned int)grid->width; x = x + 1) {
    for (; y < (unsigned int)grid->height >> 1; y = y + 1) {
      first = grid->vtable->get_value(grid, x, y);
      set_value = grid->vtable->set_value;
      second = grid->vtable->get_value(grid, x, (grid->height - y) - 1);
      set_value(grid, x, y, second);
      grid->vtable->set_value(grid, x, (grid->height - y) - 1, first);
    }
  }
}
