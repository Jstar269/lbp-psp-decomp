/* LBPMATCH module=EBOOT.BIN start=0x0896fcb8 end=0x0896fd6c symbol=FUN_0896fcb8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Header of a reference-counted object: the 16-bit count sits at offset 6. */
struct Counted0896fcb8 {
  char pad[6];
  short refcount;
};

struct Owner0896fcb8 {
  char pad[0x10];
  int *target;
};

extern int FUN_0896b354(int *target, struct Counted0896fcb8 **ref);
extern unsigned int FUN_0896b420(int *target, struct Counted0896fcb8 **ref);
extern void FUN_08970b6c(struct Counted0896fcb8 *object);   /* drops one reference */

/* Passes a counted copy of *source to FUN_0896b420 and, when that returns non-zero, to FUN_0896b354. */
void FUN_0896fcb8(struct Owner0896fcb8 *self, struct Counted0896fcb8 **source)
{
  int result;
  int *target;
  struct Counted0896fcb8 *ref2;
  struct Counted0896fcb8 *ref1;

  ref1 = *source;
  target = self->target;
  if (ref1 != 0) {
    ref1->refcount = ref1->refcount + 1;
  }
  result = FUN_0896b420(target, &ref1);
  if (ref1 != 0) {
    FUN_08970b6c(ref1);
  }
  if (result != 0) {
    ref2 = *source;
    target = self->target;
    if (ref2 != 0) {
      ref2->refcount = ref2->refcount + 1;
    }
    FUN_0896b354(target, &ref2);
    if (ref2 != 0) {
      FUN_08970b6c(ref2);
    }
  }
}
