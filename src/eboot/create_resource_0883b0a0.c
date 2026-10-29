/* LBPMATCH module=EBOOT.BIN start=0x0883b0a0 end=0x0883b1bc symbol=FUN_0883b0a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the handle temporary is declared 32 bytes aligned to 8 (retail frame), locals declared in reverse order, key copied field by field b then a. */
typedef struct Pair { int a, b; } Pair;
typedef struct Handle { int a, b; int rest[6]; } __attribute__((aligned(8))) Handle;
typedef struct Obj { void **vtbl; int pad[0x29]; int f2a; int f2b; } Obj;
extern void *DAT_08badf20;
extern void *DAT_08be84a8;
extern void FUN_08a9c304(Handle *out, Pair *key);
extern void FUN_08aaa9a0(Handle *p);
extern int FUN_08a9d790(Pair *p);
extern int FUN_08aaa780(int *p);
extern Obj *FUN_08a9e838(unsigned size);
extern void FUN_08839938(Obj *o, int arg);
extern int FUN_08aaa924(void *mgr, Obj *o);
extern void FUN_08a9bff8(Handle *p);
Obj **FUN_0883b0a0(Obj **out, Pair *key)
{
    int it;
    Pair c2;
    Pair c1;
    Pair k;
    Handle tmp;
    Obj *obj = 0;
    k.b = key->b;
    k.a = key->a;
    FUN_08a9c304(&tmp, &k);
    FUN_08aaa9a0(&tmp);
    c1.a = tmp.a; c1.b = tmp.b;
    it = FUN_08a9d790(&c1);
    if (!FUN_08aaa780(&it)) {
        int arg;
        c2.a = tmp.a; c2.b = tmp.b;
        arg = FUN_08a9d790(&c2);
        obj = FUN_08a9e838(176);
        FUN_08839938(obj, arg);
        obj->vtbl = &DAT_08badf20;
        obj->f2b = 16;
        obj->f2a = 0;
        if (!(((int (*)(Obj *))obj->vtbl[3])(obj) && FUN_08aaa924(DAT_08be84a8, obj))) {
            ((void (*)(Obj *))obj->vtbl[1])(obj);
            obj = 0;
        }
    }
    *out = obj;
    FUN_08a9bff8(&tmp);
    return out;
}
