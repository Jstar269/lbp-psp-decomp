/* LBPMATCH module=EBOOT.BIN start=0x08962c30 end=0x08962ca0 symbol=FUN_08962c30 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Flagged {
  char unk_00[4];
  unsigned char unk_04;
};

extern struct Flagged *DAT_08be8480;
extern int DAT_08befcac;
extern int DAT_08bf03b8;
extern void FUN_0895cce4();
extern int FUN_0896f064();
extern void FUN_08998604();
extern void FUN_08998858();

void FUN_08962c30(void)
{
  int looked_up;

  looked_up = FUN_0896f064(DAT_08bf03b8);
  FUN_08998604(looked_up);
  looked_up = FUN_0896f064(DAT_08bf03b8);
  FUN_08998858(looked_up);
  if ((DAT_08be8480 != 0) && (DAT_08be8480->unk_04 != 0)) {
    FUN_0895cce4(DAT_08befcac, 0x13);
    return;
  }
  return;
}
