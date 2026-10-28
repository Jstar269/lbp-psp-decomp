/* LBPMATCH module=EBOOT.BIN start=0x08b8b734 end=0x08b8b78c symbol=FUN_08b8b734 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
/* Header stored right before the characters of the string body (the layout of a reference-counted string). */
struct StrHeader {
  int length;     /* -0xc: added to the data pointer to get the end */
  int unk_08;     /* -8: not used here */
  int refcount;   /* -4: FUN_08b8b6d8 is called first when this is >= 0 */
};

struct Str {
  char *data;
};

extern void FUN_08b8b6d8(struct Str *str);

/* Returns (through `out`) the end of the string's characters; FUN_08b8b6d8 is called first when refcount >= 0. */
char **FUN_08b8b734(char **out, struct Str *str)
{
  char *data;

  data = str->data;
  if (-1 < ((struct StrHeader *)data)[-1].refcount) {
    FUN_08b8b6d8(str);
    data = str->data;
  }
  *out = data + ((struct StrHeader *)data)[-1].length;
  return out;
}
