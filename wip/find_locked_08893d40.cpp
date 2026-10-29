/* LBPMATCH module=EBOOT.BIN start=0x08893d40 end=0x08893e38 symbol=FUN_08893d40 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Key { int w[9]; };
struct Container { char pad[0x30]; int lock; };
class RefPtr {
public:
    int *p;
    RefPtr(const RefPtr &);
    ~RefPtr();
};
extern "C" void FUN_0888b8c4(int *l);
extern "C" void FUN_0888b8cc(int *l);
extern "C" RefPtr FUN_08893c68(Container *c, const Key &k, bool create);
extern "C" RefPtr FUN_08893d40(Container *c, const char *k)
{
    FUN_0888b8c4(&c->lock);
    Key tmp;
    if (((unsigned int)k & 3) == 0)
        __builtin_memcpy(&tmp, (const Key *)k, 36);
    else
        __builtin_memcpy(&tmp, k, 36);
    RefPtr r = FUN_08893c68(c, tmp, true);
    FUN_0888b8cc(&c->lock);
    return r;
}
// NEAR (~60 words): same wrapper shape as the EXACT 0x08896abc; the 36-byte key copy has a runtime alignment dispatch in retail (andi s0,3; aligned lw/sw loop, else lwl/lwr loop; last word's sw shared by both arms).
// Our compiler never emits the dispatch itself; the two source-level arms above reproduce both loops but duplicate the tail (85 words). A plain __builtin_memcpy gives the lwl/lwr arm only (47 words).
// near miss from lane lbp10c (unreviewed)
