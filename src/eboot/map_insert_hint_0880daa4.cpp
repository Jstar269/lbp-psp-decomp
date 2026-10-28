/* LBPMATCH module=EBOOT.BIN start=0x0880daa4 end=0x0880dc50 symbol=FUN_0880daa4 lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/map_insert_hint_088058a8.cpp (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::insert_unique(iterator hint, const value&) (GCC 4.0) for unsigned keys; the key comparisons go through a comparator taking references, so the key is reloaded after the iterator step calls, as in retail. */
struct Node { int color; Node *parent; Node *left; Node *right; unsigned key; };
struct Base { int color; Node *parent; Node *left; Node *right; };
struct Tree { int compare; Base header; unsigned count; };
struct Iter { Node *node; Iter(Node *n) : node(n) {} };
struct Pair { Iter first; bool second; Pair(Iter a, bool b) : first(a), second(b) {} };
inline bool lt(const unsigned &a, const unsigned &b) { return a < b; }
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_08b89838(Node *n);
extern "C" Iter FUN_0880d488(Tree *t, Node *x, Node *p, const unsigned &v);
extern "C" Pair FUN_0880d9bc(Tree *t, const unsigned &v);
extern "C" Iter FUN_0880daa4(Tree *t, Node *position, const unsigned &v)
{
    if (position == (Node *)&t->header) {
        if (t->count > 0 && lt(t->header.right->key, v))
            return FUN_0880d488(t, 0, t->header.right, v);
        else
            return FUN_0880d9bc(t, v).first;
    } else if (lt(v, position->key)) {
        Node *before = position;
        if (position == t->header.left)
            return FUN_0880d488(t, t->header.left, t->header.left, v);
        else if (lt((before = FUN_08b898a8(before))->key, v)) {
            if (before->right == 0)
                return FUN_0880d488(t, 0, before, v);
            else
                return FUN_0880d488(t, position, position, v);
        } else
            return FUN_0880d9bc(t, v).first;
    } else if (lt(position->key, v)) {
        Node *after = position;
        if (position == t->header.right)
            return FUN_0880d488(t, 0, t->header.right, v);
        else if (lt(v, (after = FUN_08b89838(after))->key)) {
            if (position->right == 0)
                return FUN_0880d488(t, 0, position, v);
            else
                return FUN_0880d488(t, after, after, v);
        } else
            return FUN_0880d9bc(t, v).first;
    } else
        return position;
}
