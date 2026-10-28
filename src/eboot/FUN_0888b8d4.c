/* LBPMATCH module=EBOOT.BIN start=0x0888b8d4 end=0x0888b9e4 symbol=FUN_0888b8d4 lang=c99 cc=gcc402x-Os rodata=0x08bb0e98 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g9); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Maps a markup element to a style flag: <br> and <b> by tag name, <font color="..."> by colour name (strings read
   from the retail data are noted next to each extern). 0 when nothing matches. */
enum MarkupStyle {
  STYLE_NONE = 0,
  STYLE_BR = 0x4,
  STYLE_B = 0x8,
  STYLE_COLOR_BLACK = 0x10,
  STYLE_COLOR_RED = 0x20,
  STYLE_COLOR_GREEN = 0x40,
  STYLE_COLOR_PINK = 0x80,
  STYLE_COLOR_BLUE = 0x100
};

struct Name0888b8d4 {
  char pad[8];
  char text[1];                 /* tag name, starts at offset 8 */
};

struct Element0888b8d4 {
  char pad[0x20];
  struct Name0888b8d4 *name;
};

extern char DAT_08bb0e90[];     /* "font" */
extern char DAT_08bb5f00[];     /* "red" */
extern char DAT_08bb0eb0[];     /* "blue" */
extern char DAT_08bb0eb8[];     /* "pink" */
extern char DAT_08bc1e60[];     /* "b" */
extern char DAT_08bb0ec0[];     /* "br" */
extern char *FUN_08844114(struct Element0888b8d4 *element, const char *attribute);
extern int FUN_08ba0d98(const char *a, const char *b);      /* returns 0 when the strings are equal */

unsigned int FUN_0888b8d4(struct Element0888b8d4 *element)
{
  int differs;
  unsigned int style;
  char *color;
  char *tag;

  tag = element->name->text;
  differs = FUN_08ba0d98(tag, DAT_08bb0e90);
  if (differs == 0) {
    color = FUN_08844114(element, "color");
    if (color == 0) {
      return STYLE_NONE;
    }
    differs = FUN_08ba0d98(color, "black");
    if (differs == 0) {
      return STYLE_COLOR_BLACK;
    }
    differs = FUN_08ba0d98(color, DAT_08bb5f00);
    if (differs == 0) {
      return STYLE_COLOR_RED;
    }
    differs = FUN_08ba0d98(color, "green");
    if (differs == 0) {
      return STYLE_COLOR_GREEN;
    }
    differs = FUN_08ba0d98(color, DAT_08bb0eb0);
    if (differs == 0) {
      return STYLE_COLOR_BLUE;
    }
    differs = FUN_08ba0d98(color, DAT_08bb0eb8);
    style = STYLE_COLOR_PINK;
  }
  else {
    differs = FUN_08ba0d98(tag, DAT_08bc1e60);
    if (differs == 0) {
      return STYLE_B;
    }
    differs = FUN_08ba0d98(tag, DAT_08bb0ec0);
    style = STYLE_BR;
  }
  if (differs != 0) {
    return STYLE_NONE;
  }
  return style;
}
