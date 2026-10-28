/* Object with a vtable, a width and a height whose cells are read and written through virtual calls
   (FUN_08aa3a68, FUN_08aa3b54). Only the two vtable slots used there are declared. */
#ifndef LBP_GRID_H
#define LBP_GRID_H

struct Grid;

struct GridVtable {
  char pad[0xc];
  unsigned int (*get_value)(struct Grid *self, unsigned int x, unsigned int y);   /* slot at +0xc */
  void (*set_value)(struct Grid *self, unsigned int x, unsigned int y, unsigned int value);  /* slot at +0x10 */
};

struct Grid {
  const struct GridVtable *vtable;
  int width;
  int height;
};

#endif
