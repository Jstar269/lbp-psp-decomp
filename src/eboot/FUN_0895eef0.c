/* LBPMATCH module=EBOOT.BIN start=0x0895eef0 end=0x0895ef80 symbol=FUN_0895eef0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
struct StateInfo {
  char unk_00[0x28];
  int count;                 /* +0x28 */
};

struct Controller {
  struct StateInfo *(**vtable)();   /* slot 25 (+100) returns the StateInfo */
  char unk_04[0x98];
  int *unk_9c;                      /* +0x9c: passed to FUN_08a1d7d0 */
};

struct Globals {
  char unk_00[0x20];
  struct Controller *controller;    /* +0x20: may be null */
};

struct Target {
  char unk_00[0x7c];
  unsigned int *data;               /* +0x7c: optional; forwarded to FUN_08a2f27c */
};

extern struct Globals *DAT_08beed14;
extern void FUN_08a1d7d0();
extern int FUN_08a2f27c(float amount, unsigned int *data);

/* If the target has data and the controller reports a positive count in its state info,
   applies `amount` to the data and then calls FUN_08a1d7d0 on the controller's +0x9c member. */
void FUN_0895eef0(float amount, struct Target *target)
{
  struct StateInfo *info;
  struct Controller *controller;

  if (target->data != 0
      && (controller = DAT_08beed14->controller, controller != 0)
      && (info = (*controller->vtable[25])(controller), 0 < info->count)) {
    FUN_08a2f27c(amount, target->data);
    FUN_08a1d7d0(controller->unk_9c);
  }
}
