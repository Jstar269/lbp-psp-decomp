/* LBPMATCH module=EBOOT.BIN start=0x08a4367c end=0x08a438b8 symbol=FUN_08a4367c lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/save_stream_floats_08a43440.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
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
    char pad0[0x2d8];
    float f0;
    int i1;
    int i2;
    float f3;
    float f4;
    float f5;
    float f6;
} Obj;
extern unsigned char FUN_08954cc4(int p);
extern void FUN_08a34774(Obj *o, Wrap *w, unsigned int tag);
extern void FUN_08a56ec8(void *sub, Wrap *w, Obj *o);
extern void FUN_0895541c(Wrap *w);
static inline void put_float(Wrap *w, float val)
{
    Stream *s = w->s;
    float v = val;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
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
void FUN_08a4367c(Obj *o, Wrap *w)
{
    FUN_08a34774(o, w, 0x52504243);
    FUN_08a56ec8((char *)o + 0xbc, w, o);
    put_float(w, o->f0);
    put_int(w, o->i1);
    put_int(w, o->i2);
    put_float(w, o->f3);
    put_float(w, o->f4);
    put_float(w, o->f5);
    put_float(w, o->f6);
    FUN_0895541c(w);
}
