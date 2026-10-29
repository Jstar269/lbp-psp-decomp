/* LBPMATCH module=EBOOT.BIN start=0x08aa744c end=0x08aa74a0 symbol=FUN_08aa744c lang=c99 */
/* Clone of src/eboot/FUN_08a1ad68.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void *FUN_08a9e838(int size);
extern void FUN_08aa73d0(void *obj, int a, int b);
void *FUN_08aa744c(int unused, int a, int b)
{
  void *p = FUN_08a9e838(0x30);
  FUN_08aa73d0(p, a, b);
  return p;
}
