/* LBPMATCH module=EBOOT.BIN start=0x0887a2d0 end=0x0887a378 symbol=FUN_0887a2d0 lang=c++ */
/* Clone of src/eboot/find_locked_08896abc.cpp (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Key { int w[5]; };
struct PKey { char b[20]; } __attribute__((packed));
struct Container { char pad[0x2c]; int lock; };
class RefPtr {
public:
    int *p;
    RefPtr(const RefPtr &);
    ~RefPtr();
};
extern "C" void FUN_0888f6b8(int *l);
extern "C" void FUN_0888f6c0(int *l);
extern "C" RefPtr FUN_0887a024(Container *c, const Key &k, bool create);
extern "C" RefPtr FUN_0887a2d0(Container *c, const PKey *k)
{
    FUN_0888f6b8(&c->lock);
    Key tmp;
    __builtin_memcpy(&tmp, k, sizeof(Key));
    RefPtr r = FUN_0887a024(c, tmp, true);
    FUN_0888f6c0(&c->lock);
    return r;
}
