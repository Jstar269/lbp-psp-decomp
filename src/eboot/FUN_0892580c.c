/* LBPMATCH module=EBOOT.BIN start=0x0892580c end=0x089258dc symbol=FUN_0892580c lang=c99 */
/* Clone of src/eboot/FUN_089251d8.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); the count is re-read from the object after the allocation call (matching idiom: local copy); exact match verified; names and types await human review. */
struct Slot {
  char data[0x70];
};
struct Pool {
  struct Slot *mem;
  struct Slot **free_list;
  int count;
  int top;
  int pad;
  unsigned char flag;
};
extern void FUN_08adb8a4(void *p);
extern void *FUN_08adb810(int size, int align, int a, int b);

void FUN_0892580c(struct Pool *p, int count, unsigned char flag)
{
  if (p->mem) FUN_08adb8a4(p->mem);
  p->mem = 0;
  p->free_list = 0;
  p->count = count;
  p->top = 0;
  if (count > 0) {
    int i;
    int bytes = count * sizeof(struct Slot);
    struct Slot *mem = FUN_08adb810(bytes + count * sizeof(struct Slot *), 16, 0, 0);
    int n = p->count;
    struct Slot **fl = (struct Slot **)(mem + n);
    p->mem = mem;
    p->free_list = fl;
    for (i = 0; i < n; i++) fl[i] = p->mem + i;
  }
  p->flag = flag;
}
