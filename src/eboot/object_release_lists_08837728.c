/* LBPMATCH module=EBOOT.BIN start=0x08837728 end=0x08837808 symbol=FUN_08837728 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node12 { struct Node12 *next; int a; int b; };
struct Node48 { int pad0; int pad4; struct Node48 *next; int key; char rest[32]; };
struct Inner { int pad0; int pad1; struct Node48 *head; };
struct Obj {
  int pad0[3];
  struct Inner inner;        /* +12 */
  int pad1[3];
  void *r9;                  /* +36 */
  char pad2[64 - 36 - 4];
  void *r16;                 /* +64 */
  void *r17;                 /* +68 */
  char pad3[260 - 72];
  void *r41;                 /* +260 */
  char pad4[288 - 264];
  struct Node12 list;        /* +288 */
};
extern void *DAT_08be84a0;
extern void FUN_088050b8(void *p);
extern void FUN_08837090(struct Inner *a, int b);
extern void FUN_088375fc(struct Obj *o);
extern void FUN_08adbc24(void *pool, void *p, int size);
void FUN_08837728(struct Obj *o)
{
  struct Node12 *n; struct Node48 *p;
  FUN_088375fc(o);
  struct Node12 *end = &o->list;
  n = end->next;
  while (n != end) {
    struct Node12 *next = n->next;
    FUN_08adbc24(DAT_08be84a0, n, 12);
    n = next;
  }
  if (o->r41) FUN_088050b8(o->r41);
  if (o->r17) FUN_088050b8(o->r17);
  if (o->r16) FUN_088050b8(o->r16);
  if (o->r9) FUN_088050b8(o->r9);
  struct Inner *in = &o->inner; p = in->head;
  while (p) {
    FUN_08837090(in, p->key);
    struct Node48 *next = p->next;
    FUN_08adbc24(DAT_08be84a0, p, 48);
    p = next;
  }
}
