/* LBPMATCH module=EBOOT.BIN start=0x0894e7c8 end=0x0894e89c symbol=FUN_0894e7c8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Lock { int x; };
struct Pool { int pad; void **items; int cap; int next; int allocated; };
extern struct Lock DAT_08bef8f4;
extern struct Pool DAT_08bef8b8;
extern void FUN_08ad3088(struct Lock *);
extern void FUN_08ad2810(struct Lock *);
extern void *FUN_08adb810(int, int, int, int);
extern void FUN_0894e758(void *);
void **FUN_0894e7c8(void **out)
{
  void *p;
  FUN_08ad3088(&DAT_08bef8f4);
  FUN_08ad3088(&DAT_08bef8f4);
  struct Pool *pl = &DAT_08bef8b8;
  int i = pl->next;
  if (i < pl->cap) {
    p = pl->items[i];
    pl->next = i + 1;
    if (p == 0) goto done;
  } else {
    pl->allocated++;
    p = FUN_08adb810(88, 16, 0, 0);
  }
  FUN_0894e758(p);
done:
  FUN_08ad2810(&DAT_08bef8f4);
  *out = p;
  FUN_08ad2810(&DAT_08bef8f4);
  return out;
}
// NEAR ~37 words: retail has 'jal init; nop' + 'j; nop' jump-over shape (older scheduler); Os/O2/gcc402x/410/171 all differ; goto form for the null slot.
// near miss from lane lbp11d (unreviewed)
