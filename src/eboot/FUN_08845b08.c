/* LBPMATCH module=EBOOT.BIN start=0x08845b08 end=0x08845b90 symbol=FUN_08845b08 lang=c99 */
/* Clone of src/eboot/FUN_08844050.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Child {
  void (**vtable)(struct Child *);
  char pad[0x24];
  struct Child *next;
};
struct Obj {
  void **vtable;
  char pad0[0x14];
  struct Child *first;
  int pad1;
  void *buffer;
};
extern void *DAT_08bae1a0[];
extern void *DAT_08bae3e8[];
extern char DAT_08bedb94[];
extern void FUN_08a9e0c4(void *);
extern void FUN_08a9e0cc(void *);

void FUN_08845b08(struct Obj *o)
{
  struct Child *c;
  o->vtable = DAT_08bae1a0;
  c = o->first;
  while (c != 0) {
    struct Child *next = c->next;
    c->vtable[1](c);
    c = next;
  }
  if (o->buffer != DAT_08bedb94 && o->buffer != 0)
    FUN_08a9e0c4(o->buffer);
  o->vtable = DAT_08bae3e8;
  FUN_08a9e0cc(o);
}
