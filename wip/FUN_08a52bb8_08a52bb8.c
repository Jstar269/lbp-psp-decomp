/* LBPMATCH module=EBOOT.BIN start=0x08a52bb8 end=0x08a52c44 symbol=FUN_08a52bb8 lang=c99 */
extern int FUN_0880c280(int, unsigned *, ...);
struct T { int a; int b; int c; int d; int e; int size; };
int FUN_08a52bb8(int p, unsigned *k)
{
  unsigned key2;
  unsigned key1;
  int n;
  struct T *t = (struct T *)(p + 0x5a4);
  if (t->size == 0) {
    key1 = *k;
    n = FUN_0880c280(p, &key1, (int)t);
    if (p + 4 == n) return 0;
    return *(int *)(n + 0x14);
  } else {
    key2 = *k;
    n = FUN_0880c280((int)t, &key2);
    if (n == p + 0x5a8) return 0;
    return *(int *)(n + 0x14);
  }
}
// NEAR (30 words, structure differs): retail has two stack key slots (sp+4 for the empty-size arm, sp+0 for the other), first arm falls through, second arm placed after with a shared epilogue; Os/O2 and swapped arm order all differ in layout
// near miss from lane lbp4b (unreviewed)
