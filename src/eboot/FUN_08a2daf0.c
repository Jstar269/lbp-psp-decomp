/* LBPMATCH module=EBOOT.BIN start=0x08a2daf0 end=0x08a2dbac symbol=FUN_08a2daf0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

struct Owner08a2daf0 {
  char pad[0x250];
  void *owned[7];               /* words 0x94..0x9a, released from the last to the first */
};

extern unsigned int DAT_08bee648;
extern void FUN_088050b8(void *owned);
extern void FUN_0894a554(struct Owner08a2daf0 *self);

/* Destroys each non-null owned object of self (last slot first), runs FUN_0894a554 on self and clears DAT_08bee648. */
void FUN_08a2daf0(struct Owner08a2daf0 *self)
{
  void *object;

  if (self->owned[6] == 0) {
    object = self->owned[5];
  }
  else {
    FUN_088050b8(self->owned[6]);
    object = self->owned[5];
  }
  if (object == 0) {
    object = self->owned[4];
  }
  else {
    FUN_088050b8(object);
    object = self->owned[4];
  }
  if (object == 0) {
    object = self->owned[3];
  }
  else {
    FUN_088050b8(object);
    object = self->owned[3];
  }
  if (object == 0) {
    object = self->owned[2];
  }
  else {
    FUN_088050b8(object);
    object = self->owned[2];
  }
  if (object == 0) {
    object = self->owned[1];
  }
  else {
    FUN_088050b8(object);
    object = self->owned[1];
  }
  if (object == 0) {
    object = self->owned[0];
  }
  else {
    FUN_088050b8(object);
    object = self->owned[0];
  }
  if (object != 0) {
    FUN_088050b8(object);
  }
  FUN_0894a554(self);
  DAT_08bee648 = 0;
}
