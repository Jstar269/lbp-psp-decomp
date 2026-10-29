/* LBPMATCH module=EBOOT.BIN start=0x08a9c604 end=0x08a9c6b0 symbol=FUN_08a9c604 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp7a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct { char *begin, *end; } Buffer;
typedef struct { char *start; int size; Buffer buf; } Str;
typedef struct { char *start; int size; } View;
extern void FUN_0894af10(void *, int, char *);
Str *FUN_08a9c604(Str *s, View *v) {
 int n = s->size, m = v->size;
 char *src = v->start, *limit, *dst;
 Buffer *b = &s->buf;
 char c = 0;
 FUN_0894af10(b,n+m+1,&c);
 limit = src+m;
 dst = b->begin+n;
 while (src != limit) *dst++ = *src++;
 *dst = 0;
 { char *finish = b->end; char *base = b->begin; s->start = base; s->size = finish - base - 1; }
 return s;
}
