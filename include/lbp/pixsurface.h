/* A linear pixel surface as used by the rectangle fill routines. */
#ifndef LBP_PIXSURFACE_H
#define LBP_PIXSURFACE_H

typedef struct PixSurface {
  int pixels;   /* address of the first pixel */
  int width;    /* columns filled by the whole-surface fill (FUN_08aa2fe8) */
  int stride;   /* pixels per row (not bytes) */
  int height;   /* rows filled by the whole-surface fill */
} PixSurface;

#endif
