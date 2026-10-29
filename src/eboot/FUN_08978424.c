/* LBPMATCH module=EBOOT.BIN start=0x08978424 end=0x089784a4 symbol=FUN_08978424 lang=c99 */
/* Clone of src/eboot/FUN_088d1634.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node {
  void **vtable;
  short size;
  short flag;
  int a;
  int b;
};
extern void *DAT_08bbd8a8[];
extern void *DAT_08be84a0;
extern struct Node *FUN_08adbb84(void *heap, int size);

struct Node **FUN_08978424(struct Node **out, int a, int *b)
{
  struct Node *n = FUN_08adbb84(DAT_08be84a0, 16);
  if (n != 0) {
    int v = *b;
    n->flag = 1;
    n->a = a;
    n->vtable = DAT_08bbd8a8;
    n->b = v;
    n->size = 16;
  }
  *out = n;
  return out;
}
