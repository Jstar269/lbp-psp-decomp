/* LBPMATCH module=EBOOT.BIN start=0x0893785c end=0x08937888 symbol=FUN_0893785c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Inner {
  char pad[0x34];
  int unk_34;
  int unk_38;
  unsigned short flags;    /* +0x3c: bit 0x20 selects the other handler */
};

struct Outer {
  struct Inner *inner;
};

extern int FUN_0893773c();
extern void FUN_089377f0();

void FUN_0893785c(void *unused, struct Outer *outer)
{
  struct Inner *inner = outer->inner;

  inner->unk_34 = 0;
  inner->unk_38 = 0;
  if ((inner->flags & 0x20) != 0) {
    FUN_089377f0(outer);
    return;
  }
  FUN_0893773c(outer);
}
