/* LBPMATCH module=EBOOT.BIN start=0x0896cd08 end=0x0896cda0 symbol=FUN_0896cd08 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct LNode {
  LNode *next;
  LNode *prev;
  int pad;
};
struct Pool;
extern "C" void *DAT_08bb8940[];
extern "C" Pool *DAT_08be84a0;
extern "C" void FUN_08adbc24(Pool *pool, void *p, int size);
struct List;
extern "C" void FUN_0896c85c(List *l);
struct List {
  LNode head;
  int pad[3];
  ~List()
  {
    FUN_0896c85c(this);
    LNode *n = head.next;
    while (n != (LNode *)this) {
      LNode *nx = n->next;
      FUN_08adbc24(DAT_08be84a0, n, 12);
      n = nx;
    }
  }
};
struct Base_0896b250 {
  ~Base_0896b250();
};
struct Owner : Base_0896b250 {
  void **vt;
  int pad[5];
  List lists[2];
  ~Owner() { vt = DAT_08bb8940; }
};
extern "C" void FUN_0896cd08(Owner *self)
{
  self->~Owner();
}
// NEAR: member-array destructor; the genuine C++ form (List has an inline ~List, Owner : Base_0896b250 holds List lists[2],
// '~Owner() { vt = ...; }', base dtor symbol _ZN13Base_0896b250D2Ev appended to symbols/) reproduces retail's compiler-generated
// array-destroy loop (li 3 / addiu -1 / beqz, the '&lists != 0' guard, tail call to the base dtor). 35 words differ because ours
// strength-reduces a second induction variable (s3) for the list head loads, where retail uses the element pointer (s1) only.
// near miss from lane lbp9a (unreviewed)
