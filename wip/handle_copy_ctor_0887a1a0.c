/* LBPMATCH module=EBOOT.BIN start=0x0887a1a0 end=0x0887a220 symbol=FUN_0887a1a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Shared { int f0; int count; } Shared;
typedef struct Handle { int a; unsigned char b; int c; Shared *p; } Handle;
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);
void FUN_0887a1a0(Handle *dst, const Handle *src)
{
    Shared *p = src->p;
    int a = src->a;
    unsigned char b = src->b;
    int c = src->c;
    dst->a = a;
    dst->b = b;
    dst->c = c;
    dst->p = p;
    if (p) {
        FUN_08ad3088(DAT_08bef8f4);
        p->count++;
        FUN_08ad2810(DAT_08bef8f4);
    }
}
// NEAR 5 words: only register choice differs (retail: int field a -> v1, byte b -> a2; ours a -> a2, b -> v1) and load order. Tried: 24 load orders, 24 store orders, struct copy, C++ copy ctor with AddRef member.
// near miss from lane lbp8b (unreviewed)
