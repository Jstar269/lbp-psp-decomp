/* LBPMATCH module=EBOOT.BIN start=0x08a650d4 end=0x08a65110 symbol=FUN_08a650d4 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_08ac97c0 on the handle at +0x270 when FUN_08ac980c reports it non-zero, and clears the byte at +0x2b4. */
struct HasHandle {
  char pad[0x270];
  int handle;                /* +0x270 */
  char pad2[0x40];
  unsigned char flag_2b4;    /* +0x2b4 */
};

extern void FUN_08ac97c0();
extern int FUN_08ac980c();

void FUN_08a650d4(struct HasHandle *self)
{
  int active;

  active = FUN_08ac980c(self->handle);
  if (active == 0) {
    self->flag_2b4 = 0;
  }
  else {
    FUN_08ac97c0(self->handle);
    self->flag_2b4 = 0;
  }
  return;
}
