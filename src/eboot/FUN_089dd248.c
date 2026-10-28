/* LBPMATCH module=EBOOT.BIN start=0x089dd248 end=0x089dd2b4 symbol=FUN_089dd248 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Forwards `arg` to the child at +0x44 when bytes +0x4c and the child allow it (byte +0x4d set, or flag 0x200
   clear in the flags word at +4), then always calls FUN_089e0c5c. */
#define FLAG_0x200 0x200

struct WithChild {
  char pad[4];
  unsigned int flags;        /* +4 */
  char pad2[0x3c];
  int *child;                /* +0x44 */
  char pad3[4];
  unsigned char use_child;   /* +0x4c */
  unsigned char force_child; /* +0x4d */
};

extern void FUN_0896aeec();
extern void FUN_089e0c5c();

void FUN_089dd248(struct WithChild *self, int arg)
{
  if (((self->use_child != '\0') && (self->child != (int *)0x0)) &&
     ((self->force_child != '\0' || ((self->flags & FLAG_0x200) == 0)))) {
    FUN_0896aeec(self->child, arg);
  }
  FUN_089e0c5c(self, arg);
  return;
}
