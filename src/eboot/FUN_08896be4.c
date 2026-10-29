/* LBPMATCH module=EBOOT.BIN start=0x08896be4 end=0x08896ce8 symbol=FUN_08896be4 lang=c99 */
/* Clone of src/eboot/FUN_0887a378.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Key {
  int w[5];
};
struct Node {
  int pad[4];
  struct Key key;           /* 16 */
  int value[1];             /* 36 */
};
struct Tree {
  int pad;
  int header;               /* 4 */
  int pad2[3];
  int count;                /* 20 */
};
struct Pool {
  char pad[32];
  int lock[1];              /* 32 */
};
struct Entry {
  struct Key key;
  int value[1];
};
extern struct Pool *DAT_08be84ac;
extern int FUN_08ba0d98(const unsigned char *a, const unsigned char *b);
extern void FUN_08ad3088(int *lock);
extern void FUN_08ad2810(int *lock);
extern struct Node *FUN_08adbb84(struct Pool *pool, int size);
extern void FUN_08896b64(int *dst, int *src);
extern void FUN_08b899e4(int left, struct Node *z, struct Node *p, int *header);

struct Node *FUN_08896be4(struct Tree *t, struct Node *x, struct Node *p, struct Entry *v)
{
  int left;
  struct Pool *pool;
  struct Node *z;
  struct Key *k;
  if (x != 0 || p == (struct Node *)&t->header ||
      FUN_08ba0d98((const unsigned char *)v, (const unsigned char *)&p->key) < 0)
    left = 1;
  else
    left = 0;
  pool = DAT_08be84ac;
  FUN_08ad3088(pool->lock);
  z = FUN_08adbb84(pool, 52);
  FUN_08ad2810(pool->lock);
  k = &z->key;
  if (k != 0) {
    *k = v->key;
    FUN_08896b64(z->value, v->value);
  }
  FUN_08b899e4(left, z, p, &t->header);
  t->count = t->count + 1;
  return z;
}
