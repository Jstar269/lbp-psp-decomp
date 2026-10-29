/* LBPMATCH module=EBOOT.BIN start=0x08891714 end=0x08891788 symbol=FUN_08891714 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  void *vt;
  char pad[0x28];
  char member[1];
};
extern void *DAT_08bb0ff8[];
extern char DAT_08beF8f4[];
extern char DAT_08bedae0[];
extern struct Obj *DAT_08bedd04;
extern void FUN_08ad3088(void *lock);
extern void FUN_08ad2810(void *lock);
extern void FUN_08890410(void *p, int a, int b);
extern void FUN_0888b898(void *p);
extern void FUN_08890a48(struct Obj *p);

void FUN_08891714(struct Obj *self)
{
  self->vt = DAT_08bb0ff8;
  FUN_08ad3088(DAT_08beF8f4);
  FUN_08890410(DAT_08bedae0, 0, 0);
  FUN_08ad2810(DAT_08beF8f4);
  FUN_0888b898(self->member);
  FUN_08890a48(self);
  DAT_08bedd04 = 0;
}
// NEAR 2 words: retail issues `sw s1,4(sp)` between `lui v0` and `addiu v0` of the vtable address; ours puts addiu first.
// Tried: RAII Lock class in C++ (worse), lock as int object, vtable as non-array, gcc404xs-O2. Same 2 words.
// near miss from lane lbp12b (unreviewed)
