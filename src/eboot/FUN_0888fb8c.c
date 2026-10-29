/* LBPMATCH module=EBOOT.BIN start=0x0888fb8c end=0x0888fbfc symbol=FUN_0888fb8c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte copy: __builtin_memcpy into an int[5] member (lwl/lwr + sw). */
extern const void *FUN_08882764(void);
typedef struct Obj { int key[5]; int a,b,c; short d; } Obj;
void FUN_0888fb8c(Obj *self){ __builtin_memcpy(self->key,FUN_08882764(),20); self->a=0;self->b=0;self->c=0;self->d=0; }
