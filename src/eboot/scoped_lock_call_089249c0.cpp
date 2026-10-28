/* LBPMATCH module=EBOOT.BIN start=0x089249c0 end=0x08924a18 symbol=FUN_089249c0 lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Calls FUN_089248e4 on the global object DAT_08beee10 under a scoped lock of the global mutex DAT_08bef8f4 (lock FUN_08ad3088, unlock FUN_08ad2810 as a tail call); the lock holds a reference to the mutex, which is why retail keeps only the %hi part live and rebuilds the address for the unlock. */
extern "C" void FUN_08ad3088(void *m);
extern "C" void FUN_08ad2810(void *m);
struct Mutex { int x; void Lock() { FUN_08ad3088(this); } void Unlock() { FUN_08ad2810(this); } };
struct ScopedLock { Mutex &m; ScopedLock(Mutex &mm) : m(mm) { m.Lock(); } ~ScopedLock() { m.Unlock(); } };
extern Mutex DAT_08bef8f4;
extern char DAT_08beee10[];
extern "C" void FUN_089248e4(void *self, void *a, bool b);
extern "C" void FUN_089249c0(void *a, bool b)
{
    ScopedLock lock(DAT_08bef8f4);
    FUN_089248e4(DAT_08beee10, a, b);
}
