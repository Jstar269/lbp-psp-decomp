/* LBPMATCH module=EBOOT.BIN start=0x0897107c end=0x08971144 symbol=FUN_0897107c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g10); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* A heap object whose first word is another owned pointer. */
struct Box0897107c {
  void *inner;
};

struct Owner0897107c {
  char pad[0x2ac];
  struct Box0897107c *box_2ac;
  struct Box0897107c *box_2b0;
  struct Box0897107c *box_2b4;
  struct Box0897107c *box_2b8;
};

extern void FUN_088050b8(void *inner);
extern void FUN_08a9e0cc(void *box);

/* Destroys and clears the four boxes of self: the inner object first (when set), then the box itself. */
void FUN_0897107c(struct Owner0897107c *self)
{
  struct Box0897107c *box;

  box = self->box_2b4;
  if (box != 0) {
    if (box->inner != 0) {
      FUN_088050b8(box->inner);
    }
    FUN_08a9e0cc(box);
  }
  box = self->box_2b0;
  self->box_2b4 = 0;
  if (box != 0) {
    if (box->inner != 0) {
      FUN_088050b8(box->inner);
    }
    FUN_08a9e0cc(box);
  }
  box = self->box_2b8;
  self->box_2b0 = 0;
  if (box != 0) {
    if (box->inner != 0) {
      FUN_088050b8(box->inner);
    }
    FUN_08a9e0cc(box);
  }
  box = self->box_2ac;
  self->box_2b8 = 0;
  if (box != 0) {
    if (box->inner != 0) {
      FUN_088050b8(box->inner);
    }
    FUN_08a9e0cc(box);
  }
  self->box_2ac = 0;
}
