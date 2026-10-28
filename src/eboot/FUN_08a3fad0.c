/* LBPMATCH module=EBOOT.BIN start=0x08a3fad0 end=0x08a3fb20 symbol=FUN_08a3fad0 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct VObject {
  void (**vtable)();
};

extern void FUN_08a348ac(float value, struct VObject *obj);

/* Calls virtual slots 61 and 27 on the object, then FUN_08a348ac. */
void FUN_08a3fad0(float value, struct VObject *obj)
{
  obj->vtable[61](obj);
  obj->vtable[27](obj);
  FUN_08a348ac(value, obj);
}
