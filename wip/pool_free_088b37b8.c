/* LBPMATCH module=EBOOT.BIN start=0x088b37b8 end=0x088b3898 symbol=FUN_088b37b8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { void (**vt)(struct Obj *); } Obj;
typedef struct Pool {
  char *base;
  Obj **slots;
  int count;
  int freecount;
  int heapcount;
} Pool;
extern Pool DAT_08be8430;
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);
extern void FUN_08adb8a4(void *);

void FUN_088b37b8(char *q)
{
  Obj *p = (Obj *)(q - 8);

  FUN_08ad3088(DAT_08bef8f4);
  if ((char *)p >= DAT_08be8430.base && (char *)p < DAT_08be8430.base + DAT_08be8430.count * 24) {
    DAT_08be8430.freecount--;
    DAT_08be8430.slots[DAT_08be8430.freecount] = p;
    p->vt[0](p);
  } else if (p != 0) {
    DAT_08be8430.heapcount--;
    p->vt[0](p);
    FUN_08adb8a4(p);
  }
  FUN_08ad2810(DAT_08bef8f4);
}
// NEAR 24 words at gcc404xs-Os: logic matches; retail block layout puts the heap-free block right after the pool block with the p!=0 test at the end (O2-like reorder); O2 gives 52 words (hoists the mutex lui into s2 where retail does not).
// near miss from lane lbp9c (unreviewed)
