/* LBPMATCH module=EBOOT.BIN start=0x0894a860 end=0x0894a868 symbol=FUN_0894a860 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g12); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern int FUN_0894a7ec();

/* Object whose +8 word is the handle forwarded to FUN_0894a7ec. */
struct HandleOwner {
  unsigned char unk_00[8];
  int handle;   /* +8 */
};

void FUN_0894a860(struct HandleOwner *self, int arg)
{
  FUN_0894a7ec(self->handle, arg);
}
