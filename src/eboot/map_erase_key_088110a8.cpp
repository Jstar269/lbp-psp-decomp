/* LBPMATCH module=EBOOT.BIN start=0x088110a8 end=0x08811134 symbol=FUN_088110a8 lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/map_erase_key_088107a0.cpp (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" Iter FUN_0880d62c(Tree *t, const unsigned &k);
extern "C" Iter FUN_0880d5f4(Tree *t, const unsigned &k);
extern "C" void FUN_08810ff8(Tree *t, Iter first, Iter last);
inline IterPair equal_range(Tree *t, const unsigned &k) { return IterPair(FUN_0880d62c(t, k), FUN_0880d5f4(t, k)); }
extern "C" unsigned FUN_088110a8(Tree *t, const unsigned &k)
{
    IterPair p = equal_range(t, k);
    unsigned n = distance(p.first, p.second);
    FUN_08810ff8(t, p.first, p.second);
    return n;
}
