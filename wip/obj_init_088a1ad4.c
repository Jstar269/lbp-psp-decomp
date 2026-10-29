/* LBPMATCH module=EBOOT.BIN start=0x088a1ad4 end=0x088a1bb4 symbol=FUN_088a1ad4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Reg Reg;
typedef struct Pk { int v; } __attribute__((packed)) Pk;
typedef struct Obj {
    char pad0[0x0c];
    int link[1];
    unsigned int hash;
    int *table;
    int fill;
} Obj;
extern Reg *FUN_0889d194(void);
extern int FUN_0889d094(Reg *r);
extern void *FUN_08a9e824(int n);
extern long long FUN_0889d0dc(Reg *r, void *p);
extern unsigned int FUN_08adbd60(const char *s);
void FUN_088a1ad4(Obj *o, const char *name, Pk fill)
{
    int i;
    int *p = &o->fill;
    o->table = 0;
    *p = fill.v;
    o->table = FUN_08a9e824(FUN_0889d094(FUN_0889d194()) * 4);
    for (i = 0; i < FUN_0889d094(FUN_0889d194()); i++)
        o->table[i] = *p;
    unsigned int h;
    if (name == 0 || *name == 0) h = 0; else h = FUN_08adbd60(name);
    o->hash = h;
    FUN_0889d0dc(FUN_0889d194(), &o->link);
}
// NEAR: only the 4-byte copy of the packed-struct param differs: retail stores a2 to 0(sp) then lwl/lwr from the stack and sw to +24;
// ours forwards a2 (sw a2,24(a0)) and the sp spill goes after the call. Tried: packed int struct, char[4] struct, short pair struct,
// memcpy(p,&fill,4), struct assign, aligned(1) int typedef, cast through pointer (param kept in a register), C++ (not finished).
// Matching idioms: long long return type on FUN_0889d0dc (retail does not tail call); int *p=&o->fill hoisted (retail s3=a0+24).
// near miss from lane lbp10c (unreviewed)
