/* LBPMATCH module=EBOOT.BIN start=0x08a6e160 end=0x08a6e3ac symbol=FUN_08a6e160 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct { char pad[144]; int id; int unused; int value; unsigned count; int *items; } Obj;
typedef struct { char pad[4]; char *cur; char p[12]; int off; char q[24]; void *owner; } Stream;
extern void FUN_08a34774(Obj *, Stream **, int);
extern void *FUN_08a50fbc(void);
extern char *FUN_08a52bb8(void *, int *);
extern int FUN_08954cc4(void *);
extern void FUN_0895541c(Stream **);
static inline void put(Stream *s, int v) { if (!FUN_08954cc4(s->owner)) __builtin_memcpy(s->cur, &v, 4); s->off += 4; s->cur += 4; }
void FUN_08a6e160(Obj *o, Stream **s) {
 unsigned i; int n=0, value; char *r;
 FUN_08a34774(o,s,0x424f594d);
 void *ctx=FUN_08a50fbc(); value=o->value;
 if(o->id != -1) { r=FUN_08a52bb8(ctx,&o->id); if(r && *(int *)(r+68)==35) value=-1; }
 put(*s,value);
 char flags[o->count];
 for(i=0;i<o->count;i++) { r=FUN_08a52bb8(FUN_08a50fbc(), &o->items[i]); flags[i]=(!r || r[55]); if(flags[i]) n++; }
 put(*s,n);
 for(i=0;i<o->count;i++) if(flags[i]) put(*s,o->items[i]);
 FUN_0895541c(s);
}


// Near: variable stack allocation and stream writer scheduling differ; O2 also tested.
// near miss from lane lbp15d (unreviewed)
