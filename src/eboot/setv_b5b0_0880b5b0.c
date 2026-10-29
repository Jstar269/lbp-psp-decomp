/* LBPMATCH module=EBOOT.BIN start=0x0880b5b0 end=0x0880b604 symbol=FUN_0880b5b0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_08a3b778(int);
extern int FUN_08a50fbc(void);
extern void FUN_08a52140(int, int);
struct G { char pad[0x464]; float v; };
extern struct G *DAT_08be8510;
extern float DAT_08bab59c;
void FUN_0880b5b0(void)
{
  int *p = (int *)FUN_08a3b778(2);
  if (p != 0)
    FUN_08a52140(FUN_08a50fbc(), p[1]);
  DAT_08be8510->v = DAT_08bab59c;
}
