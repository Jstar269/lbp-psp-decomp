/* LBPMATCH module=EBOOT.BIN start=0x088f65dc end=0x088f6650 symbol=FUN_088f65dc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int FUN_089eb734();
extern void * FUN_089ecaa8();

typedef struct Obj88f65dc {
  char pad_00[0x44];
  int state;      /* 0 = fresh; 1..8 = already started; 9 or more refuses the call */
  char pad_48[0x58];
  int value;
} Obj88f65dc;

/* Returns 1 when the value was accepted, 0 when state is 9 or more. */
int FUN_088f65dc(Obj88f65dc *self, int new_value)
{
  int current;
  void *instance;
  int result;

  result = 0;
  if (self->state < 9) {
    if (self->state == 0) {
      self->state = 1;
      instance = FUN_089ecaa8();
      FUN_089eb734((int)instance,1,0);
      current = self->value;
    }
    else {
      current = self->value;
    }
    result = 1;
    if (new_value != current) {
      self->value = new_value;
    }
  }
  return result;
}
