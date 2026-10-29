/* LBPMATCH module=EBOOT.BIN start=0x08a2e9a0 end=0x08a2ea74 symbol=FUN_08a2e9a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Pool {
    char *mem;
    char **free_list;
    int count;
    int used;
    int f10;
    unsigned char flag;
} Pool;
extern void FUN_08adb8a4(void *p);
extern void *FUN_08adb810(unsigned size, int align, int a, int b);
void FUN_08a2e9a0(Pool *p, int n, unsigned char flag)
{
    if (p->mem)
        FUN_08adb8a4(p->mem);
    p->mem = 0;
    p->free_list = 0;
    p->count = n;
    p->used = 0;
    if (n > 0) {
        char *mem = FUN_08adb810(((n * 28 + 15) & ~15) + n * 4, 16, 0, 0);
        int cnt = p->count;
        char **fl;
        p->mem = mem;
        fl = (char **)(mem + ((cnt * 28 + 15) & ~15));
        p->free_list = fl;
        if (cnt > 0) {
            int i = 0;
            do {
                i++;
                *fl++ = mem;
                mem += 28;
            } while (cnt != i);
        }
    }
    p->flag = flag;
}
// NEAR ~5 words: retail copies loop state through 3 extra register moves (fl in v1, cur in v0, i in a0, one word longer); ours keeps mem in a0 and uses v1 as counter. Tried: cur copy, for loop, do/while with guard.
// near miss from lane lbp8b (unreviewed)
