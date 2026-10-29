/* LBPMATCH module=EBOOT.BIN start=0x08845a84 end=0x08845b08 symbol=FUN_08845a84 lang=c++ */
/* Clone of src/eboot/FUN_08843f48.cpp (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern "C" void FUN_08a9e0c4(void *p);
extern "C" char DAT_08bedb94[];
extern "C" void *DAT_08bae1a0[];
extern "C" void *DAT_08bae3e8[];
struct Item {
  virtual void v0();
  virtual void destroy();
  char pad[0x24];
  Item *next; /* +0x28 */
};
struct Owner {
  void **vt;
  char pad[0x14];
  Item *head;     /* +0x18 */
  char pad2[4];
  void *buf;      /* +0x20 */
};
extern "C" void FUN_08845a84(Owner *self)
{
  self->vt = DAT_08bae1a0;
  Item *it = self->head;
  while (it) {
    Item *n = it->next;
    it->destroy();
    it = n;
  }
  void *b = self->buf;
  if (b != DAT_08bedb94 && b != 0) FUN_08a9e0c4(b);
  self->vt = DAT_08bae3e8;
}
