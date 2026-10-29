/* LBPMATCH module=EBOOT.BIN start=0x08a56258 end=0x08a56314 symbol=FUN_08a56258 lang=c99 cc=gcc404xs-O2 */
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
extern unsigned char FUN_08954cc4(int p);
static inline void put_float(Wrap *w, float *src)
{
    Stream *s = w->s;
    float v = *src;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
void FUN_08a56258(Wrap *w, float *src)
{
    put_float(w, src);
    put_float(w, src + 1);
}
