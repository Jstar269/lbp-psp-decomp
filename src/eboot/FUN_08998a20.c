/* LBPMATCH module=EBOOT.BIN start=0x08998a20 end=0x08998a8c symbol=FUN_08998a20 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* When the byte at +0x3c is set, asks the FUN_0895a96c object (FUN_08959524) and, if that says 0 and its byte
   at +0x50 is clear, runs FUN_08998858 on `self`. */
struct HasFlag3c {
  char pad[0x3c];
  unsigned char enabled;     /* +0x3c */
};

struct Other {
  char pad[0x50];
  unsigned char flag_50;     /* +0x50 */
};

extern int FUN_08959524();
extern struct Other *FUN_0895a96c();
extern void FUN_08998858();

void FUN_08998a20(struct HasFlag3c *self)
{
  struct Other *other;
  int status;

  if (self->enabled != '\0') {
    other = FUN_0895a96c();
    status = FUN_08959524(other);
    if ((status == 0) && (other->flag_50 == '\0')) {
      FUN_08998858(self);
      return;
    }
  }
  return;
}
