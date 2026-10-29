/* LBPMATCH module=EBOOT.BIN start=0x089273d4 end=0x08927480 symbol=FUN_089273d4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ref { void (**vt)(void *); int count; } Ref;
typedef struct Obj { int a,b; Ref *ref; } Obj;
extern char DAT_08bef8f4; extern char *DAT_08be84ac;
extern void FUN_08b88fc8(void *), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08adbc24(void *, void *, int);
void FUN_089273d4(Obj **p) {
 Obj *o = *p; Ref *r; int count; char *heap;
 FUN_08b88fc8(o); r=o->ref;
 if (r) { FUN_08ad3088(&DAT_08bef8f4); count=--r->count; FUN_08ad2810(&DAT_08bef8f4); if (!count) r->vt[2](r); }
 heap=DAT_08be84ac; FUN_08ad3088(heap+32); FUN_08adbc24(heap,o,12); FUN_08ad2810(heap+32);
}
