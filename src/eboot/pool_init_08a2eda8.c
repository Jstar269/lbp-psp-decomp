/* LBPMATCH module=EBOOT.BIN start=0x08a2eda8 end=0x08a2ee60 symbol=FUN_08a2eda8 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/pool_init_08a2ec1c.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the size n * 36 is written as (n << 5) + (n << 2) (retail shifts by 2 first); the loop re-reads the count after the allocation call. */
struct Slot { char pad[32]; };
struct Pool { struct Slot *slots; struct Slot **freelist; int count; int used; int pad; unsigned char flag; };
extern void *FUN_08adb810(int, int, int, int);
extern void FUN_08adb8a4(void *);
void FUN_08a2eda8(struct Pool *p, int n, unsigned char flag)
{
  int i;
  struct Slot *s;
  struct Slot **q;
  if (p->slots != 0)
    FUN_08adb8a4(p->slots);
  p->slots = 0;
  p->freelist = 0;
  p->count = n;
  p->used = 0;
  if (n > 0) {
    int cnt;
    s = FUN_08adb810((n << 5) + (n << 2), 16, 0, 0);
    cnt = p->count;
    p->slots = s;
    q = (struct Slot **)(s + cnt);
    p->freelist = q;
    if (cnt > 0) {
      i = 0;
      do {
        q[i] = s + i;
        i++;
      } while (cnt != i);
    }
  }
  p->flag = flag;
}
