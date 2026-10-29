/* LBPMATCH module=EBOOT.BIN start=0x08896abc end=0x08896b64 symbol=FUN_08896abc lang=c++ */
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
extern "C" void FUN_0888b8c4(int *l);
extern "C" void FUN_0888b8cc(int *l);
extern "C" RefPtr FUN_088969e4(Container *c, const Key &k, bool create);
extern "C" RefPtr FUN_08896abc(Container *c, const PKey *k)
{
    FUN_0888b8c4(&c->lock);
    Key tmp;
    __builtin_memcpy(&tmp, k, sizeof(Key));
    RefPtr r = FUN_088969e4(c, tmp, true);
    FUN_0888b8cc(&c->lock);
    return r;
}
