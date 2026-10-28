/* LBPMATCH module=EBOOT.BIN start=0x08886d50 end=0x08886ddc symbol=FUN_08886d50 lang=c++ cc=gcc404xs-Os */
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
extern "C" Iter FUN_08885894(Tree *t, const unsigned &k);
extern "C" Iter FUN_0888583c(Tree *t, const unsigned &k);
extern "C" void FUN_08886c6c(Tree *t, Iter first, Iter last);
inline IterPair equal_range(Tree *t, const unsigned &k) { return IterPair(FUN_08885894(t, k), FUN_0888583c(t, k)); }
extern "C" unsigned FUN_08886d50(Tree *t, const unsigned &k)
{
    IterPair p = equal_range(t, k);
    unsigned n = distance(p.first, p.second);
    FUN_08886c6c(t, p.first, p.second);
    return n;
}
