/* LBPMATCH module=EBOOT.BIN start=0x08a6f93c end=0x08a6f9d8 symbol=FUN_08a6f93c lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Item {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
  virtual void v11();
  virtual void v12();
  virtual void v13();
  virtual void v14();
  virtual void v15();
  virtual void v16();
  virtual void v17();
  virtual void v18();
  virtual void v19();
  virtual void v20();
  virtual void v21();
  virtual void v22();
  virtual void v23();
  virtual void v24();
  virtual void v25();
  virtual void v26();
  virtual void v27();
  virtual void v28();
  virtual void v29();
  virtual void v30();
  virtual void v31();
  virtual void v32();
  virtual void v33();
  virtual void v34();
  virtual void v35();
  virtual void v36();
  virtual void v37();
  virtual void v38();
  virtual void v39();
  virtual int query(int flag);
  char pad[0x37 - 4 - 41 * 0];
};
struct Node;
struct Entry {
  char pad[0x37];
  unsigned char active;
};
struct Node {
  int pad[5];
  Item *item;
};
struct Tree {
  int pad;
  char header[4];
  int root;
  Node *first;
};
extern "C" Node *FUN_08b898a0(Node *n);
extern "C" int FUN_08a6f93c(Tree *t, unsigned char flag)
{
  int sum = 0;
  Node *end = (Node *)t->header;
  Node *n = t->first;
  if (n != end) {
    do {
      while (!((unsigned char *)n->item)[0x37]) {
        n = FUN_08b898a0(n);
        if (end == n) return sum;
      }
      sum += n->item->query(flag);
      n = FUN_08b898a0(n);
    } while (end != n);
  }
  return sum;
}
// NEAR: list walk summing a virtual call (slot 0xa0/4) over entries whose flag byte (+0x37) is set; cc=gcc404xs-O2 gets the
// register roles right (sum s3, flag s2) but 29 words differ: retail re-masks the flag (andi a1,s2,0xff) at each call, enters the
// loop body directly (bne s0,s1) and reuses the item pointer register for the vtable load. Os layout is worse (35).
// near miss from lane lbp9a (unreviewed)
