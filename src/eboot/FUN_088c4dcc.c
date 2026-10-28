/* LBPMATCH module=EBOOT.BIN start=0x088c4dcc end=0x088c4e64 symbol=FUN_088c4dcc lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int FUN_08959524();
extern struct Manager *FUN_0895a96c();
extern void FUN_0895b95c();

struct Manager {
  unsigned char unk_00[0xab];
  unsigned char flag_ab;   /* +0xab */
};

struct Target {
  unsigned int unk_00;
  unsigned int mask;       /* +4: one bit per index */
  unsigned char unk_08[0xb4];
  unsigned int bit_index;  /* +0xbc */
};

struct Source {
  unsigned char unk_00[0x14];
  struct Target *target;   /* +0x14 */
};

/* When the target's mask has the bit its bit_index selects, and the manager (FUN_0895a96c) has flag_ab
   clear and FUN_08959524 returns 0, calls FUN_0895b95c(manager, 0, 0). */
void FUN_088c4dcc(struct Source *self)
{
  struct Manager *manager;
  int busy;

  if (self->target != 0 && (manager = FUN_0895a96c(), manager->flag_ab == 0)) {
    manager = FUN_0895a96c();
    busy = FUN_08959524(manager);
    if (busy == 0 && (self->target->mask & 1 << (self->target->bit_index & 0x1f)) != 0) {
      manager = FUN_0895a96c();
      FUN_0895b95c(manager, 0, 0);
    }
  }
}
