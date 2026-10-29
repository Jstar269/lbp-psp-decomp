/* LBPMATCH module=EBOOT.BIN start=0x08a1ad68 end=0x08a1adbc symbol=FUN_08a1ad68 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern void *FUN_08a9e838(int size);
extern void FUN_08a1acb0(void *obj, int a, int b);
void *FUN_08a1ad68(int unused, int a, int b)
{
  void *p = FUN_08a9e838(0x30);
  FUN_08a1acb0(p, a, b);
  return p;
}
