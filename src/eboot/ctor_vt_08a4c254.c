/* LBPMATCH module=EBOOT.BIN start=0x08a4c254 end=0x08a4c2d8 symbol=FUN_08a4c254 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11a, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: __builtin_memcpy into a char[20] member for the unaligned copy. */
extern char DAT_08bc5cf0[];
extern char DAT_08bc5cd0[];

typedef struct Obj {
  void *vt;
  int f4;
  char data[20];
  int f1c;
  int f20;
  int f24;
} Obj;

void FUN_08a4c254(Obj *self, const void *src, int b, int c)
{
  self->vt = DAT_08bc5cf0;
  self->f1c = 13;
  self->f4 = 0;
  __builtin_memcpy(self->data, src, 20);
  self->vt = DAT_08bc5cd0;
  self->f20 = b;
  self->f24 = c;
}
