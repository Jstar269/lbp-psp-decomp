/* LBPMATCH module=EBOOT.BIN start=0x08a4568c end=0x08a45790 symbol=FUN_08a4568c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++'s std::vector<T>::reserve (GCC 4.0) for a 4-byte trivially copyable element, over the game's operator new/delete. */
extern "C" void FUN_08b886b0(const char *what) __attribute__((noreturn));
extern "C" void FUN_08b8829c(void) __attribute__((noreturn));
extern "C" void *FUN_08a9e838(unsigned size);
extern "C" void FUN_08a9e0cc(void *p);
extern "C" void *FUN_08b9e8cc(void *dst, const void *src, unsigned n);
extern const char DAT_08bb1b40[];
typedef int T;
struct Vec {
    T *start;
    T *finish;
    T *end_of_storage;
    unsigned max_size() const { return 0x3fffffff; }
    unsigned capacity() const { return end_of_storage - start; }
    unsigned size() const { return finish - start; }
    inline void reserve(unsigned n);
};
inline void Vec::reserve(unsigned n)
{
    if (n > max_size())
        FUN_08b886b0(DAT_08bb1b40);
    if (capacity() < n) {
        const unsigned old_size = size();
        if (n > max_size())
            FUN_08b8829c();
        T *tmp = static_cast<T *>(FUN_08a9e838(n * sizeof(T)));
        FUN_08b9e8cc(tmp, start, (finish - start) * sizeof(T));
        if (start)
            FUN_08a9e0cc(start);
        start = tmp;
        finish = tmp + old_size;
        end_of_storage = tmp + n;
    }
}
extern "C" void FUN_08a4568c(Vec *v, unsigned n) { v->reserve(n); }
// NEAR (~60 words, structural): std::vector<4-byte T>::reserve. Retail tests n>max_size once (sltu v1), branches to an out-of-line pair "length_error(str); bad_alloc()" placed at the function end, and keeps the second n>max_size test in allocate (bnez v1 again). Ours with both callees noreturn drops the second test and keeps the throw inline; without noreturn it calls them inline; -O2 not better. Needs a profile that does not thread the second test (maybe -O1-like).
// near miss from lane lbp8a (unreviewed)
