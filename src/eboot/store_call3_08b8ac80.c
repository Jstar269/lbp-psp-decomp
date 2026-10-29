/* LBPMATCH module=EBOOT.BIN start=0x08b8ac80 end=0x08b8acb4 symbol=FUN_08b8ac80 lang=c99 */
/* Clone of src/eboot/store_call3_08b8ab1c.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_08b8aa40(int a, int b, int c);
void FUN_08b8ac80(int *self, int a, int b, int c)
{
    *self = FUN_08b8aa40(a, b, c);
}
