/* LBPMATCH module=EBOOT.BIN start=0x088d3710 end=0x088d37b8 symbol=FUN_088d3710 lang=c99 */
/* Clone of src/eboot/refcount_init_08826fd0.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Heap { char pad[32]; char lock[1]; } Heap;
typedef struct Holder { void *ptr; int *count; } Holder;
extern Heap *DAT_08be84ac;
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);
extern int *FUN_08adbb84(Heap *, int);
void FUN_088d3710(Holder *h, void *p)
{
    h->ptr = p;
    if (p) {
        Heap *heap = DAT_08be84ac;
        int *c;
        FUN_08ad3088(heap->lock);
        c = FUN_08adbb84(heap, 4);
        FUN_08ad2810(heap->lock);
        h->count = c;
        FUN_08ad3088(DAT_08bef8f4);
        *c = 1;
        FUN_08ad2810(DAT_08bef8f4);
    } else {
        h->count = 0;
    }
}
