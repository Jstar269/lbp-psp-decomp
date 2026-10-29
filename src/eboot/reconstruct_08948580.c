/* LBPMATCH module=EBOOT.BIN start=0x08948580 end=0x089485fc symbol=FUN_08948580 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Big { char pad0[0x614]; char sub[0x94]; unsigned int f6a8; };
extern struct Big *DAT_08bedb1c;
extern unsigned int DAT_08bef8d8;
extern unsigned char DAT_08bef8d4;
extern void FUN_089484e4(void *);
extern void FUN_0894a49c(void *);
extern int FUN_089eaa70(void *);
extern int FUN_089eaa7c(void *);
extern void *FUN_089ecaa8(void);
extern unsigned int FUN_08ad16f0(void);
extern void *FUN_08adb810(int, int, int, int);
void FUN_08948580(void)
{
  struct Big *g;
  FUN_089484e4(FUN_08adb810(0x6f8, 0x10, 0, 0));
  g = DAT_08bedb1c;
  FUN_0894a49c(g->sub);
  g->f6a8 = FUN_08ad16f0();
  DAT_08bef8d8 = FUN_089eaa70(FUN_089ecaa8());
  DAT_08bef8d4 = FUN_089eaa7c(FUN_089ecaa8());
}
