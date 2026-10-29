/* LBPMATCH module=EBOOT.BIN start=0x0893407c end=0x08934128 symbol=FUN_0893407c lang=c99 */
/* Clone of src/eboot/lane13a_089273d4.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ref { void (**vt)(void *); int count; } Ref;
typedef struct Obj { int a,b; Ref *ref; } Obj;
extern char DAT_08bef8f4; extern char *DAT_08be84ac;
extern void FUN_08b88fc8(void *), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08adbc24(void *, void *, int);
void FUN_0893407c(Obj **p) {
 Obj *o = *p; Ref *r; int count; char *heap;
 FUN_08b88fc8(o); r=o->ref;
 if (r) { FUN_08ad3088(&DAT_08bef8f4); count=--r->count; FUN_08ad2810(&DAT_08bef8f4); if (!count) r->vt[2](r); }
 heap=DAT_08be84ac; FUN_08ad3088(heap+32); FUN_08adbc24(heap,o,12); FUN_08ad2810(heap+32);
}
