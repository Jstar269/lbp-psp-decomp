/* LBPMATCH module=EBOOT.BIN start=0x08924a18 end=0x08924ad4 symbol=FUN_08924a18 lang=c99 */
/* Clone of src/eboot/pool_init_0887b830.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the size n * 36 is written as (n << 5) + (n << 2); the count is re-read after the allocation call. */
struct Slot { char pad[32]; };
struct Pool { struct Slot *slots; struct Slot **freelist; int count; int used; int pad; unsigned char flag; };
extern void *FUN_08adb810(int, int, int, int);
extern void FUN_08adb8a4(void *);
void FUN_08924a18(struct Pool *p, int n, unsigned char flag)
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
