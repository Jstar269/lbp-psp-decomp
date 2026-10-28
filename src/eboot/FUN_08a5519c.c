/* LBPMATCH module=EBOOT.BIN start=0x08a5519c end=0x08a55200 symbol=FUN_08a5519c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

extern void FUN_088266f0();

/* Passes the four consecutive words of `fields` to FUN_088266f0, tagged 0x31, 0x11, 0x12 and 0x14. */
void FUN_08a5519c(void *ctx, unsigned int *fields)
{
  FUN_088266f0(ctx, 0x31, fields);
  FUN_088266f0(ctx, 0x11, fields + 1);
  FUN_088266f0(ctx, 0x12, fields + 2);
  FUN_088266f0(ctx, 0x14, fields + 3);
}
