/* LBPMATCH module=EBOOT.BIN start=0x088fd7dc end=0x088fd830 symbol=FUN_088fd7dc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Dat08bf7304 {
  char pad_00[0x24c];
  int unk_24c;
};

struct Obj {
  char pad_00[0x18];
  unsigned char unk_18;
};

extern struct Dat08bf7304 *DAT_08bf7304;
extern void FUN_08910754(void);
extern int FUN_08a2e74c(int arg);
extern int FUN_08a50fbc(void);

/* Until the flag at +0x18 is set: ask FUN_08a2e74c about the word at +0x24c of the DAT_08bf7304 object and set the
   flag once it returns non-zero. */
void FUN_088fd7dc(struct Obj *self)
{
  int result;

  FUN_08910754();
  if (self->unk_18 == 0) {
    FUN_08a50fbc();
    result = FUN_08a2e74c(DAT_08bf7304->unk_24c);
    if (result != 0) {
      self->unk_18 = 1;
    }
  }
  return;
}
