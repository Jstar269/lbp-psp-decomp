/* LBPMATCH module=EBOOT.BIN start=0x08aa2e44 end=0x08aa2e98 symbol=FUN_08aa2e44 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
/* Row-major grid of 32-bit cells; row_stride may exceed width. */
struct WordGrid {
  unsigned int *data;
  int width;           /* cells filled per row */
  int row_stride;      /* cells between the starts of two rows */
  unsigned int height; /* number of rows */
};

/* Sets every cell of the grid (width x height) to value. */
void FUN_08aa2e44(struct WordGrid *grid, unsigned int value)
{
  unsigned int *cell;
  int column;
  unsigned int row;
  int width;

  for (row = 0; row < grid->height; row = row + 1) {
    width = grid->width;
    cell = grid->data + grid->row_stride * row;
    for (column = 0; column != width; column = column + 1) {
      *cell = value;
      cell = cell + 1;
    }
  }
  return;
}
