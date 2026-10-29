/* LBPMATCH module=EBOOT.BIN start=0x08a90460 end=0x08a90598 symbol=FUN_08a90460 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/save_stream_obj_08a398dc.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Stream {
    char pad0[4];
    char *cur;
    char pad1[0x0c];
    int count;
    char pad2[0x18];
    int owner;
} Stream;
typedef struct Wrap { Stream *s; } Wrap;
typedef struct Obj {
    char pad0[0x9c];
    char sub[0x34];
    unsigned char flag;
    int a;
    int b;
    int c;
} Obj;
extern unsigned char FUN_08954cc4(int p);
extern void FUN_08a34774(Obj *o, Wrap *w, unsigned int tag);
extern void FUN_08a56874(void *sub, Wrap *w, Obj *o);
extern void FUN_08955284(Stream *s, unsigned int v);
extern void FUN_0895541c(Wrap *w);
static inline void put_int(Wrap *w, int val)
{
    Stream *s = w->s;
    int v = val;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
void FUN_08a90460(Obj *o, Wrap *w)
{
    FUN_08a34774(o, w, 0x20535732);
    FUN_08a56874(o->sub, w, o);
    put_int(w, o->a);
    put_int(w, o->b);
    {
        Stream *s3 = w->s;
        int v = o->c;
        unsigned int f;
        Stream *s;
        if (!FUN_08954cc4(s3->owner)) {
            __builtin_memcpy(s3->cur, &v, 4);
        }
        f = o->flag;
        s = w->s;
        s3->cur += 4;
        s3->count += 4;
        FUN_08955284(s, f);
    }
    FUN_0895541c(w);
}
