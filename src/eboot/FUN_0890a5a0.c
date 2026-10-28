/* LBPMATCH module=EBOOT.BIN start=0x0890a5a0 end=0x0890a60c symbol=FUN_0890a5a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
/* Object with virtual functions; slot 1 (+4) is called to release it. */
struct Releasable {
  void (**vtable)();
  unsigned char unk_04[0x54];
  struct Checker *checker;   /* +0x58 */
};

/* Object whose virtual slot 23 (+0x5c) says whether the owner may be released. */
struct Checker {
  int (**vtable)();
};

/* If the object *slot points at has a checker and the checker's slot 23 returns nonzero,
   releases the object through its slot 1 and clears *slot. */
void FUN_0890a5a0(struct Releasable **slot)
{
  struct Checker *checker;
  struct Releasable *obj;
  int ready;

  if ((*slot != 0 && (checker = (*slot)->checker, checker != 0)) &&
      (ready = (*checker->vtable[0x5c / 4])(checker), ready != 0)) {
    obj = *slot;
    if (obj != 0) {
      (*obj->vtable[1])(obj);
    }
    *slot = 0;
  }
}
