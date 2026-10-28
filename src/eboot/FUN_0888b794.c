/* LBPMATCH module=EBOOT.BIN start=0x0888b794 end=0x0888b860 symbol=FUN_0888b794 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Obj {
  int state;
  char pad_04[0x4b4];
  void *buf_4b8;
  int unk_4bc;
  void *buf_4c0;
  int unk_4c4;
};

extern int DAT_08bee0e4;
extern unsigned char DAT_08bee0e8;
extern void FUN_08887608();
extern void FUN_0888b3a0();
extern void FUN_08a9e0c4();
extern void FUN_08baa694();
extern void FUN_08baa6bc();
extern void FUN_08baa6d4();

/* Step the state down: above 2 it is torn down to 1 (state 3 also frees its two buffers), then the
   state > 0 work runs. */
void FUN_0888b794(struct Obj *self)
{
  if (2 < self->state) {
    if (self->state == 3) {
      self->unk_4c4 = 0;
      self->unk_4bc = 0;
      if (self->buf_4b8 != 0) {
        FUN_08a9e0c4(self->buf_4b8);
      }
      if (self->buf_4c0 != 0) {
        FUN_08a9e0c4(self->buf_4c0);
      }
      self->state = 2;
      self->buf_4c0 = 0;
      self->buf_4b8 = 0;
    }
    if (DAT_08bee0e8 != 0) {
      FUN_08baa6d4();
      FUN_08baa6bc();
      FUN_08baa694();
      DAT_08bee0e8 = 0;
    }
    DAT_08bee0e4 = 0;
    self->state = 1;
  }
  if (0 < self->state) {
    FUN_0888b3a0(self);
  }
  FUN_08887608();
}
