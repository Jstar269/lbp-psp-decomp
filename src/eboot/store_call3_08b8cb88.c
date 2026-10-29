/* LBPMATCH module=EBOOT.BIN start=0x08b8cb88 end=0x08b8cbbc symbol=FUN_08b8cb88 lang=c99 */
/* Clone of src/eboot/store_call3_08b8ab1c.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern int FUN_08b8c8a0(int a, int b, int c);
void FUN_08b8cb88(int *self, int a, int b, int c)
{
    *self = FUN_08b8c8a0(a, b, c);
}
