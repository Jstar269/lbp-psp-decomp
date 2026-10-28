/* LBPMATCH module=EBOOT.BIN start=0x0890e2a0 end=0x0890e320 symbol=FUN_0890e2a0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Mode {
  unsigned int unk_00;
  int state;                /* +4: 5 triggers the call below */
};

struct Hud {
  unsigned int unk_00;
  struct Mode *mode;        /* +4 */
};

struct Globals {
  char pad[0x87c];
  struct Hud hud;           /* +0x87c: its address is passed to FUN_08910574 */
};

struct Screen {
  char pad[0x1c];
  unsigned char unk_1c;
  char pad2[0x2f];
  unsigned char unk_4c;
  char pad3[7];
  unsigned char unk_54;
};

extern struct Globals *DAT_08bf7304;
extern void FUN_0890d8ec();
extern void FUN_0890e1b0();
extern void FUN_08910574();
extern int FUN_08a50fbc();

void FUN_0890e2a0(struct Screen *self)
{
  struct Globals *globals;

  FUN_08a50fbc();
  globals = DAT_08bf7304;
  if (self->unk_4c != 0) {
    FUN_0890e1b0(self);
  }
  if (self->unk_54 != 0) {
    FUN_0890d8ec(self);
  }
  if (globals->hud.mode->state == 5) {
    FUN_08910574(&globals->hud, 1);
  }
  self->unk_1c = 0;
}
