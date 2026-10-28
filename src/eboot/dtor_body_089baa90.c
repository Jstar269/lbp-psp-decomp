/* LBPMATCH module=EBOOT.BIN start=0x089baa90 end=0x089baac4 symbol=FUN_089baa90 lang=c99 cc=gcc410-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc0a18[];
extern void FUN_0897905c(void *self);
extern void FUN_08a9e0cc(void *self);
void FUN_089baa90(void **self)
{
    *self = DAT_08bc0a18;
    FUN_0897905c(self);
    FUN_08a9e0cc(self);
}
