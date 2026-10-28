/* LBPMATCH module=EBOOT.BIN start=0x08940d60 end=0x08940ee4 symbol=FUN_08940d60 lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/refptr_get_0893ddec.cpp (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Looks a resource up by an 8-byte key in the manager (DAT_08be84a8) and, if absent, creates it, through an intrusive reference-counted pointer (count at +8 under the mutex at +20, release FUN_088050b8): the lookup result is converted from the base pointer (three AddRefs, two temporaries released). */
struct Key { unsigned a, b; };
extern "C" void FUN_08ad3088(void *m);
extern "C" void FUN_08ad2810(void *m);
struct Base { void *vtbl; int f4; int rc; int fc; int f10; int mutex;
              void AddRef() { FUN_08ad3088(&mutex); ++rc; FUN_08ad2810(&mutex); } };
struct Derived : Base {};
extern "C" void FUN_088050b8(Base *p);
template <class T> struct RefPtr {
    T *p;
    RefPtr(T *q) : p(q) { if (p) p->AddRef(); }
    RefPtr(const RefPtr &o) : p(o.p) { if (p) p->AddRef(); }
    template <class U> RefPtr(const RefPtr<U> &o) : p(static_cast<T *>(o.p)) { if (p) p->AddRef(); }
    ~RefPtr() { if (p) FUN_088050b8(p); }
    RefPtr &operator=(const RefPtr &o) { if (o.p) o.p->AddRef(); T *old = p; p = o.p; if (old) FUN_088050b8(old); return *this; }
};
extern void *DAT_08be84a8;
extern "C" Base *FUN_08aaaa80(void *mgr, Key k);
extern "C" RefPtr<Base> FUN_08877780(Key k);
extern "C" bool FUN_08940d60(void *self, Key key, RefPtr<Derived> &out)
{
    out = RefPtr<Derived>(RefPtr<Base>(FUN_08aaaa80(DAT_08be84a8, key)));
    if (out.p)
        return true;
    out = RefPtr<Derived>(FUN_08877780(key));
    return false;
}
