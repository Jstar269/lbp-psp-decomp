/* LBPMATCH module=EBOOT.BIN start=0x089ea93c end=0x089ea97c symbol=FUN_089ea93c lang=c99 cc=gcc410-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_08bc2770[];
extern char DAT_08bc27a0[];
extern void FUN_08a1fb94(void *member);
typedef struct T { void *vt; int member; } T;
void FUN_089ea93c(T *self)
{
    self->vt = DAT_08bc2770;
    FUN_08a1fb94(&self->member);
    self->vt = DAT_08bc27a0;
}
