/* LBPMATCH module=EBOOT.BIN start=0x08908e20 end=0x08908ef0 symbol=FUN_08908e20 lang=c++ */
/* Clone of src/eboot/shared_release_08826f00.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Heap { char pad[32]; char lock[1]; };
struct Mutex { int a; };
struct Object { char x; };
extern "C" void FUN_08aa98f8(Object *);
struct Holder { Object *ptr; int *count; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern Mutex DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
extern "C" void FUN_08adb8a4(void *p);
extern "C" void FUN_08908e20(Holder *h)
{
    int *count = h->count;
    if (count) {
        FUN_08ad3088(&DAT_08bef8f4);
        int n = --*count;
        FUN_08ad2810(&DAT_08bef8f4);
        if (n == 0) {
            Object *p = h->ptr;
            if (p) {
                FUN_08aa98f8(p);
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
