/* LBPMATCH module=EBOOT.BIN start=0x0885778c end=0x08857a40 symbol=FUN_0885778c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct Obj { void (**vtable)(struct Obj *); int refs; int unused; char data[20]; } Obj;
extern void FUN_08855b64(Obj **);
extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
extern char DAT_08bef8f4;
static void release(Obj *p) { int n; if (p) { FUN_08ad3088(&DAT_08bef8f4); n = --p->refs; FUN_08ad2810(&DAT_08bef8f4); if (!n) p->vtable[2](p); } }
int FUN_0885778c(int *entry, char *base, char *self) {
 Obj *p, *old; Obj **slot; char *src = base + entry[1];
 if (*entry == 0x4d4f4349) slot = (Obj **)(self + 0x2a0);
 else if (*entry == 0x4d544143) slot = (Obj **)(self + 0x294);
 else if (*entry == 0x4d4c564c) slot = (Obj **)(self + 0x288);
 else return 0;
 FUN_08855b64(&p); __builtin_memcpy(p->data, src, 20);
 if (p) { FUN_08ad3088(&DAT_08bef8f4); ++p->refs; FUN_08ad2810(&DAT_08bef8f4); }
 old = *slot; *slot = p; release(old); release(p); return 0;
}
// 173 words differ; shared slot and release helper change control-flow layout; three branch-local copies likely needed.
// near miss from lane lbp15d (unreviewed)
