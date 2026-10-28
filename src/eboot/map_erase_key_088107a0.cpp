/* LBPMATCH module=EBOOT.BIN start=0x088107a0 end=0x0881082c symbol=FUN_088107a0 lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::erase(const key&) (GCC 4.0): equal_range (lower_bound, upper_bound) inlined, std::distance by increments, then erase(first, last); equal_range is inlined only with the default -Os inline limits of gcc404xs-Os. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" NodeBase *FUN_08b89838(NodeBase *n);
struct Iter {
    NodeBase *node;
    Iter(NodeBase *n) : node(n) {}
    Iter &operator++() { node = FUN_08b89838(node); return *this; }
    bool operator!=(const Iter &o) const { return node != o.node; }
};
struct IterPair { Iter first, second; IterPair(const Iter &a, const Iter &b) : first(a), second(b) {} };
inline unsigned distance(Iter first, Iter last) { unsigned n = 0; while (first != last) { ++first; ++n; } return n; }
extern "C" Iter FUN_0880cea0(Tree *t, const unsigned &k);
extern "C" Iter FUN_0880ce68(Tree *t, const unsigned &k);
extern "C" void FUN_088106f0(Tree *t, Iter first, Iter last);
inline IterPair equal_range(Tree *t, const unsigned &k) { return IterPair(FUN_0880cea0(t, k), FUN_0880ce68(t, k)); }
extern "C" unsigned FUN_088107a0(Tree *t, const unsigned &k)
{
    IterPair p = equal_range(t, k);
    unsigned n = distance(p.first, p.second);
    FUN_088106f0(t, p.first, p.second);
    return n;
}
