/* LBPMATCH module=EBOOT.BIN start=0x08b8dfd8 end=0x08b8e050 symbol=FUN_08b8dfd8 lang=c++ cc=gcc404x-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); NEAR MISS, not exact. */
extern "C" void FUN_08b8de2c();
extern "C" void FUN_08b8df10();
extern "C" int FUN_08b8df64(char *);

struct Locker {
    bool unlock;
    Locker() : unlock(true) { FUN_08b8de2c(); }
    ~Locker() { if (unlock) FUN_08b8df10(); }
};

extern "C" int FUN_08b8dfd8(char *g)
{
    if (*g != 0) return 0;
    Locker lk;
    if (FUN_08b8df64(g)) {
        lk.unlock = false;
        return 1;
    }
    return 0;
}

// 2 words off at cc=gcc404x-O2 (exceptions on: cleanup landing pad calls FUN_08b8df10 then _Unwind_Resume 0x08b9acec, symbol line appended): retail has move s0,a0 at entry and move v1,zero in the beqz delay slot, ours swaps them.
// libstdc++ __cxa_guard_acquire shape (mutex_wrapper with unlock flag); tried r-variable forms, nested scope, !r flag
// near miss from lane lbp4d (unreviewed)
