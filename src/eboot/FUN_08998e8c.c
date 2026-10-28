/* LBPMATCH module=EBOOT.BIN start=0x08998e8c end=0x08998ed4 symbol=FUN_08998e8c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Message {
  char pad[8];
  int id;                    /* +8 */
};

struct Toggler {
  char pad[0xe0];
  unsigned char flags;       /* +0xe0: bit 0 is flipped by message 0xfaf */
};

extern struct Toggler **DAT_08bf5e44;

/* Message handler: returns 0 when message 0xfaf was consumed (it flips bit 0 of the target's flags), else 1. */
int FUN_08998e8c(void *unused, struct Message **message)
{
  struct Toggler *target;
  int result;

  result = 1;
  if (((DAT_08bf5e44 != 0) && (target = *DAT_08bf5e44, target != 0)) &&
      ((*message)->id == 0xfaf)) {
    result = 0;
    target->flags = target->flags ^ 1;
  }
  return result;
}
