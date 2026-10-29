/* LBPMATCH module=EBOOT.BIN start=0x089eda34 end=0x089eda78 symbol=FUN_089eda34 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { int color; Node *parent; Node *left; Node *right; unsigned key; };
struct Header { int color; Node *root; Node *left; Node *right; };
struct Tree { int cmp; Header header; };
extern "C" Header *FUN_089eda34(Tree *t, const unsigned *k)
{
    Node *x = t->header.root;
    Header *y = &t->header;
    while (x) {
        Node *n;
        if (*k < x->key) {
            y = (Header *)x;
            n = x->left;
        } else
            n = x->right;
        x = n;
    }
    return y;
}
// NEAR 7 words (O2): retail left path loads x->left into v0 in the bnezl slot and keeps own 'move a0,v1; beqz v0; move v1,v0' tail; ours reuses v1 and a nop slot.
// Tried: key hoisted local, do-while, for(;;), next-pointer local, break after left (all worse or equal).
// near miss from lane lbp12c (unreviewed)
