/* LBPMATCH module=EBOOT.BIN start=0x088506ac end=0x08850780 symbol=FUN_088506ac lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Str {
  char pad[12];
  char data[20];
};
struct Key {
  int pad;
  struct Str *name;
  int num;
};
struct Node {
  int pad[2];
  struct Node *left;
  struct Node *right;
  struct Key key;
};
struct Tree {
  int pad;
  char header[4];
  struct Node *root;
  int pad2[2];
  int count;
};
extern int FUN_08b9e714(const char *a, const char *b, int n);
extern struct Node *FUN_088505e0(struct Tree *t, struct Key *v);
extern void FUN_08b899e4(int left, struct Node *z, struct Node *p, void *header);

static inline int key_less(struct Key *a, struct Key *b)
{
  if (a->num != 0 || b->num != 0)
    return a->num - b->num < 0;
  return FUN_08b9e714(a->name->data, b->name->data, 20) < 0;
}

struct Node *FUN_088506ac(struct Tree *t, struct Node *x, struct Node *p, struct Key *v)
{
  int insert_left;
  struct Node *z;
  insert_left = (x != 0 || p == (struct Node *)t->header || key_less(v, &p->key));
  z = FUN_088505e0(t, v);
  FUN_08b899e4(insert_left, z, p, t->header);
  t->count++;
  return z;
}
// NEAR: 36 words differ, layout only (prologue and operations match). Retail keeps the key-compare diff block
// (subu; srl; beqz) as fallthrough and puts the memcmp-like call block after the 'insert_left = 1' stub, jumping back to the
// beqz with its own srl in the delay slot; ours keeps the call block in line and shares one srl.
// Tried: && / || forms, int c merge then c < 0 (bgez), bool results, key_less(&p->key) refs (fixed the prologue), cc O2 (57 words).
// near miss from lane lbp9a (unreviewed)
