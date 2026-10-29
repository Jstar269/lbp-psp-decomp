/* LBPMATCH module=EBOOT.BIN start=0x089e0a64 end=0x089e0abc symbol=FUN_089e0a64 lang=c99 */
/* Clone of src/eboot/func_089e0a0c.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bc1c40;
extern void FUN_0896b250(void *);
struct Obj { void *vt; unsigned flags; int pad[4]; void *child; };
void FUN_089e0a64(struct Obj *p) { p->vt=&DAT_08bc1c40; if ((p->flags & 0x1000) && p->child) { void *c=p->child; (*(void (**)(void *))(*(char **)c+4))(c); } FUN_0896b250(p); }
