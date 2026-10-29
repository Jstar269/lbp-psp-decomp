/* LBPMATCH module=EBOOT.BIN start=0x088c4f14 end=0x088c4f98 symbol=FUN_088c4f14 lang=c99 */
/* Hand-written reconstruction (lane lbp4a); NEAR. */
struct Obj;
struct VT { int pad[41]; void (*fn)(struct Obj *, float); };
struct Obj { struct VT *vt; };
struct Owner { int pad[6]; struct Obj *obj; int *list; };
struct G { char pad[0x88]; char a; char b; };
extern struct G *DAT_08bf03b8;
extern int DAT_08bf7304;
extern void FUN_088c4ea0(void);
extern void FUN_08a3a7e4(int *);
extern int FUN_08a50fbc(void);
extern void FUN_08a7e614(int, int, int);

void FUN_088c4f14(struct Owner *param_1)
{
  FUN_08a50fbc();
  if (DAT_08bf7304 != 0) {
    FUN_08a7e614(DAT_08bf7304, 1, 0);
  }
  struct G *g = DAT_08bf03b8;
  g->b = 0;
  g->a = 0;
  FUN_088c4ea0();
  if (param_1->list != 0) {
    FUN_08a3a7e4(param_1->list);
  }
  param_1->obj->vt->fn(param_1->obj, 0.0f);
  param_1->obj = 0;
}
// NEAR 2 words: only the position of mtc1 zero,f12 differs: retail has it in the jalr delay slot after the vtable loads (33 words); ours hoists it into the lw-use gap (34 words, nop in delay slot). Tried O2 (worse), local receiver, int 0 arg.
// near miss from lane lbp4a (unreviewed)
