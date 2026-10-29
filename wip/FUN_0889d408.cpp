/* LBPMATCH module=EBOOT.BIN start=0x0889d408 end=0x0889d4d4 symbol=FUN_0889d408 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Vec {
  void **begin;
  void **finish;
  void **cap_end;
};
extern "C" char DAT_08bb1b40[];
extern "C" void FUN_08b886b0(const char *msg) __attribute__((noreturn));
extern "C" void *FUN_08a9e838(unsigned size);
extern "C" void FUN_08a9e0cc(void *p);
extern "C" void *FUN_08b9e8cc(void *dst, const void *src, unsigned n);

extern "C" void FUN_0889d408(Vec *v, unsigned n)
{
  if (n > 0x3fffffff) FUN_08b886b0(DAT_08bb1b40);
  void **cap = v->cap_end;
  void **old_begin = v->begin;
  if ((unsigned)(cap - old_begin) < n) {
    void **old_finish = v->finish;
    int count = old_finish - old_begin;
    void **tmp = (void **)FUN_08a9e838(n * 4);
    FUN_08b9e8cc(tmp, old_begin, (char *)old_finish - (char *)old_begin);
    if (v->begin) FUN_08a9e0cc(v->begin);
    v->finish = tmp + count;
    v->begin = tmp;
    v->cap_end = tmp + n;
  }
}
// NEAR: 2 words differ (the order of the first two loads: retail loads end_of_storage (8) before begin (0), ours begin first).
// vector<T*>::reserve with a 'vector::reserve' length error. Needed: the element count taken as a pointer difference before the
// free call (otherwise the sra/sll pair folds into an ins), and the three stores written finish, begin, end_of_storage (scheduler
// rotation). Tried: cap local first, condition operand order, begin read inside the if, a class with inline capacity()/reserve()
// (41 words worse).
// near miss from lane lbp9a (unreviewed)
