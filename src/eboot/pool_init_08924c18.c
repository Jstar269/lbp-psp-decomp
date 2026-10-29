/* LBPMATCH module=EBOOT.BIN start=0x08924c18 end=0x08924d04 symbol=FUN_08924c18 lang=c99 */
/* Clone of src/eboot/pool_init_088855c4.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Pool {
  char *block;
  char **slots;
  int count;
  int used;
  int pad;
  unsigned char flag;
} Pool;
extern void FUN_08adb8a4(void *);
extern char *FUN_08adb810(unsigned size, int align, int a, int b);

void FUN_08924c18(Pool *p, int n, unsigned char flag)
{
  if (p->block != 0) {
    FUN_08adb8a4(p->block);
  }
  p->block = 0;
  p->slots = 0;
  p->count = n;
  p->used = 0;
  if (n > 0) {
    char *b = FUN_08adb810(((n * 100 + 15) & ~15u) + n * 4, 16, 0, 0);
    int cnt = p->count;
    char **s = (char **)(b + ((cnt * 100 + 15) & ~15u));
    int i;
    p->block = b;
    p->slots = s;
    for (i = 0; i < cnt; i++) {
      s[i] = p->block + i * 100;
    }
  }
  p->flag = flag;
}
