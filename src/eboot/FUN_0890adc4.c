/* LBPMATCH module=EBOOT.BIN start=0x0890adc4 end=0x0890ae98 symbol=FUN_0890adc4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned int DAT_08bef41c;
extern struct Globals * DAT_08bf7304;
extern void FUN_0890a23c();
extern void FUN_0890ad40();
extern void FUN_08910574();
extern void FUN_08913dd8();
extern int * FUN_08914a7c();
extern int FUN_08914e94();
extern int FUN_08a2e738();
extern int FUN_08a50fbc();

/* The global object; only the members used here are named. */
typedef struct Globals {
  char pad_000[0x24c];
  int unk_24c;
  char pad_250[0x160];
  unsigned char unk_3b0;
  char pad_3b1[0x4cb];
  char unk_87c[4];   /* passed by address to FUN_08910574 */
} Globals;

typedef struct Obj890adc4 {
  char pad_000[0x220];
  char unk_220[0x20];   /* sub-object, passed by address to FUN_0890a23c */
  unsigned char unk_240;
  unsigned char active;   /* when set, the block below runs once and clears it */
  unsigned char unk_242;
  char pad_243;
  unsigned char unk_244;
} Obj890adc4;

void FUN_0890adc4(Obj890adc4 *self, unsigned char clear_244)
{
  int *obj_a;
  int *obj_b;
  int value;
  Globals *globals;

  if (self->active != 0) {
    obj_a = FUN_08914a7c();
    obj_b = FUN_08914a7c();
    value = FUN_08914e94((int)obj_b,DAT_08bef41c);
    FUN_08913dd8(obj_a,1,value,1,0,0,0x400,0);
    FUN_08a50fbc();
    globals = DAT_08bf7304;
    FUN_08a2e738(globals->unk_24c);
    self->active = 0;
    self->unk_240 = 0;
    self->unk_242 = 0;
    FUN_0890a23c(self->unk_220);
    FUN_0890ad40(self);
    if (globals->unk_3b0 == 0) {
      FUN_08910574(globals->unk_87c,1);
    }
  }
  if (clear_244 != 0) {
    self->unk_244 = 0;
  }
}
