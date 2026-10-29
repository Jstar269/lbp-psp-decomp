/* LBPMATCH module=EBOOT.BIN start=0x0887b830 end=0x0887b8ec symbol=FUN_0887b830 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the size n * 36 is written as (n << 5) + (n << 2); the count is re-read after the allocation call. */
struct Slot { char pad[32]; };
struct Pool { struct Slot *slots; struct Slot **freelist; int count; int used; int pad; unsigned char flag; };
extern void *FUN_08adb810(int, int, int, int);
extern void FUN_08adb8a4(void *);
void FUN_0887b830(struct Pool *p, int n, unsigned char flag)
{
  int i;
  if (p->slots != 0)
    FUN_08adb8a4(p->slots);
  p->slots = 0;
  p->freelist = 0;
  p->count = n;
  p->used = 0;
  if (n > 0) {
    int cnt;
    struct Slot **q;
    p->slots = FUN_08adb810((n << 5) + (n << 2), 16, 0, 0);
    cnt = p->count;
    q = (struct Slot **)(p->slots + cnt);
    p->freelist = q;
    for (i = 0; i < cnt; i++)
      q[i] = p->slots + i;
  }
  p->flag = flag;
}
