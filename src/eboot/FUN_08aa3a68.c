/* LBPMATCH module=EBOOT.BIN start=0x08aa3a68 end=0x08aa3b54 symbol=FUN_08aa3a68 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

#include "lbp/grid.h"

/* Mirrors every row: swaps the cell at x with the cell at width - 1 - x for the left half of each row. */
void FUN_08aa3a68(struct Grid *grid)
{
  unsigned int first;
  unsigned int second;
  void (*set_value)(struct Grid *, unsigned int, unsigned int, unsigned int);
  unsigned int x;
  unsigned int y;

  for (y = 0; x = 0, y < (unsigned int)grid->height; y = y + 1) {
    for (; x < (unsigned int)grid->width >> 1; x = x + 1) {
      first = grid->vtable->get_value(grid, x, y);
      set_value = grid->vtable->set_value;
      second = grid->vtable->get_value(grid, (grid->width - x) - 1, y);
      set_value(grid, x, y, second);
      grid->vtable->set_value(grid, (grid->width - x) - 1, y, first);
    }
  }
}
