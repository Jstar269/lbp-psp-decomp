/* LBPMATCH module=EBOOT.BIN start=0x088cc71c end=0x088cc7e4 symbol=FUN_088cc71c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Heap { char pad[32]; char lock[1]; };
struct Mutex { int a; };
struct Object { char x; };
struct Holder { Object *ptr; int *count; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern Mutex DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
extern "C" void FUN_08adb8a4(void *p);
extern "C" void FUN_088cc71c(Holder *h)
{
    int *count = h->count;
    if (count) {
        FUN_08ad3088(&DAT_08bef8f4);
        int n = --*count;
        FUN_08ad2810(&DAT_08bef8f4);
        if (n == 0) {
            Object *p = h->ptr;
            if (p) {
                FUN_08adb8a4(p);
            }
            Heap *heap = sys_heap();
            int *c = h->count;
            FUN_08ad3088(heap->lock);
            FUN_08adbc24(heap, c, 4);
            FUN_08ad2810(heap->lock);
        }
    }
}
