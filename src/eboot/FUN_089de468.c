/* LBPMATCH module=EBOOT.BIN start=0x089de468 end=0x089de4b8 symbol=FUN_089de468 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Replaces the child object at +0x34 of `self` (the old one is released through virtual slot 4) and points the
   new child's field +8 back at `self`. Kept in int-typed form: with typed struct members the two stores are
   reordered by the compiler. */
void FUN_089de468(int self, int new_child)
{
  int *old_child;

  old_child = *(int **)(self + 0x34);
  if (old_child != (int *)0x0) {
    (**(void (**)(int *))(*old_child + 4))(old_child);
  }
  *(int *)(new_child + 8) = self;
  *(int *)(self + 0x34) = new_child;
  return;
}
