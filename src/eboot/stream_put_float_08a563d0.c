/* LBPMATCH module=EBOOT.BIN start=0x08a563d0 end=0x08a56430 symbol=FUN_08a563d0 lang=c99 */
/* Clone of src/eboot/stream_put_float_08a560c0.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
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
void FUN_08a563d0(Wrap *w, float *src)
{
    Stream *s = w->s;
    float v = *src;
    if (!FUN_08954cc4(s->owner)) {
        __builtin_memcpy(s->cur, &v, 4);
    }
    s->cur += 4;
    s->count += 4;
}
