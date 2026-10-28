/* LBPMATCH module=EBOOT.BIN start=0x088058a8 end=0x08805a54 symbol=FUN_088058a8 lang=c++ cc=gcc404x-Os */
/* NOTE */
struct Node { int color; Node *parent; Node *left; Node *right; unsigned key; };
struct Base { int color; Node *parent; Node *left; Node *right; };
struct Tree { int compare; Base header; unsigned count; };
struct Iter { Node *node; Iter(Node *n) : node(n) {} };
struct Pair { Iter first; bool second; Pair(Iter a, bool b) : first(a), second(b) {} };
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_08b89838(Node *n);
extern "C" Iter FUN_088055c4(Tree *t, Node *x, Node *p, const unsigned &v);
extern "C" Pair FUN_088057c0(Tree *t, const unsigned &v);
extern "C" Iter FUN_088058a8(Tree *t, Node *position, const unsigned &v)
{
    if (position == (Node *)&t->header) {
        if (t->count > 0 && t->header.right->key < v)
            return FUN_088055c4(t, 0, t->header.right, v);
        else
            return FUN_088057c0(t, v).first;
    } else if (v < position->key) {
        Node *before = position;
        if (position == t->header.left)
            return FUN_088055c4(t, t->header.left, t->header.left, v);
        else if ((before = FUN_08b898a8(before))->key < v) {
            if (before->right == 0)
                return FUN_088055c4(t, 0, before, v);
            else
                return FUN_088055c4(t, position, position, v);
        } else
            return FUN_088057c0(t, v).first;
    } else if (position->key < v) {
        Node *after = position;
        if (position == t->header.right)
            return FUN_088055c4(t, 0, t->header.right, v);
        else if (v < (after = FUN_08b89838(after))->key) {
            if (position->right == 0)
                return FUN_088055c4(t, 0, position, v);
            else
                return FUN_088055c4(t, after, after, v);
        } else
            return FUN_088057c0(t, v).first;
    } else
        return position;
}
