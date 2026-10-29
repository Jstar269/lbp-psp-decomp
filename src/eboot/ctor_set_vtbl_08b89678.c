/* LBPMATCH module=EBOOT.BIN start=0x08b89678 end=0x08b896a8 symbol=FUN_08b89678 lang=c99 */
/* Clone of src/eboot/ctor_set_vtbl_08988934.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void *vtbl; } Obj;
extern void *DAT_08bd8970;
extern void FUN_08b89538(Obj *, int, void *);
void FUN_08b89678(Obj *o, int a, void *b)
{
    FUN_08b89538(o, a, b);
    o->vtbl = &DAT_08bd8970;
}
