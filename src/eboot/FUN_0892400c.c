/* LBPMATCH module=EBOOT.BIN start=0x0892400c end=0x08924060 symbol=FUN_0892400c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08923fb4();
extern void FUN_0894a49c();
extern unsigned int FUN_08ad16f0();
extern void *FUN_08adb810();

/* The object DAT_08bef76c points at: a sub-object at +8 and a word at +0x9c. */
struct Instance {
  char unk_00[8];
  char sub_08[0x94];
  unsigned int unk_9c;
};

extern struct Instance *DAT_08bef76c;

void FUN_0892400c(void)
{
  struct Instance *instance;
  void *memory;
  unsigned int value;

  memory = FUN_08adb810(0xb0,0x10,0,0);
  FUN_08923fb4(memory);
  instance = DAT_08bef76c;
  FUN_0894a49c(DAT_08bef76c->sub_08);
  value = FUN_08ad16f0();
  instance->unk_9c = value;
  return;
}
