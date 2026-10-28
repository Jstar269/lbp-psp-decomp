/* LBPMATCH module=EBOOT.BIN start=0x08901c08 end=0x08901c58 symbol=FUN_08901c08 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Config {
  char pad_00[4];
  unsigned char unk_04;
};

struct Obj {
  char pad_00[0x354];
  unsigned char unk_354;
  char pad_355[0x35f];
  int unk_6b4;
};

extern struct Config *DAT_08be8480;
extern struct Obj *DAT_08bf7304;
extern int FUN_08a50fbc();
extern void FUN_08a7e614();

void FUN_08901c08(void)
{
  struct Obj *obj;
  struct Config *config;

  FUN_08a50fbc();
  obj = DAT_08bf7304;
  config = DAT_08be8480;
  obj->unk_354 = 0;
  if (config != 0 && config->unk_04 != 0) {
    obj->unk_6b4 = 1;
  }
  FUN_08a7e614(obj, 1, 1);
}
