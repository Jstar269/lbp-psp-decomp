/* LBPMATCH module=EBOOT.BIN start=0x088143f4 end=0x08814438 symbol=FUN_088143f4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct O { char pad[0x72]; unsigned char flag; char pad2[9]; int val; } O;
extern void FUN_08814204(void *o, int b);
void FUN_088143f4(O *o, int b, int v, unsigned char f)
{
  FUN_08814204(o, b);
  o->val = v;
  o->flag = f;
}
// statement order: val store written before the flag store.
