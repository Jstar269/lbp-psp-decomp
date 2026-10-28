/* LBPMATCH module=EBOOT.BIN start=0x0894fad8 end=0x0894fb20 symbol=FUN_0894fad8 lang=c99 cc=gcc171-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int FUN_08a9e4a4(int x, int a, int b);
typedef struct R { int f0; int f4; int f8; } R;
void FUN_0894fad8(R *r, int x)
{
    int v = FUN_08a9e4a4(x, 0, 0);
    r->f8 = v ? x : 0;
    r->f4 = v;
}
