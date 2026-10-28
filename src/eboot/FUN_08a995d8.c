/* LBPMATCH module=EBOOT.BIN start=0x08a995d8 end=0x08a99644 symbol=FUN_08a995d8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
extern int FUN_08a50fbc();             /* the registry object */
extern unsigned int FUN_08a52b38();    /* (registry, id): looks an id up in the registry */

/* Resolves two ids through the registry and stores the results in *out_a and *out_b.
   The first parameter is not used. */
void FUN_08a995d8(int unused, unsigned int id_a, unsigned int id_b, unsigned int *out_a, unsigned int *out_b)
{
  int registry;

  registry = FUN_08a50fbc();
  *out_a = FUN_08a52b38(registry, id_a);
  registry = FUN_08a50fbc();
  *out_b = FUN_08a52b38(registry, id_b);
}
