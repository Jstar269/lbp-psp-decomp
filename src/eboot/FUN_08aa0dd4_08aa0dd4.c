/* LBPMATCH module=EBOOT.BIN start=0x08aa0dd4 end=0x08aa0e30 symbol=FUN_08aa0dd4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct G { int pad[4]; int *b; int *e; };
extern struct G *DAT_08bf9350;
extern int *FUN_08aa0d0c(int *, int *, int *);
extern void FUN_08baa97c(int);
extern void FUN_08aa0b70(int *, int *);
void FUN_08aa0dd4(int x)
{
  int *it = FUN_08aa0d0c(DAT_08bf9350->b, DAT_08bf9350->e, &x);
  FUN_08baa97c(x);
  FUN_08aa0b70(&DAT_08bf9350->b, it);
}
