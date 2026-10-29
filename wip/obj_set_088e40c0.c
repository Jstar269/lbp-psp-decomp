/* LBPMATCH module=EBOOT.BIN start=0x088e40c0 end=0x088e4208 symbol=FUN_088e40c0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp12a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
typedef struct Src { W5 k; char pad14[60 - 20]; unsigned char b60; char pad61[80 - 61]; int items[1]; } Src;
typedef struct Ctx { char pad[452]; Src *src; } Ctx;
typedef struct Obj {
  char pad0[0x24];
  int x24;
  int x28;
  char pad2c[0x55 - 0x2c];
  unsigned char b85;
  char pad56[0x78 - 0x56];
  W5 data;
  int src;
} Obj;
typedef struct Arg { int tag; int val; } Arg;
extern int DAT_08bb440c;
extern Ctx *DAT_08beed14;
extern int DAT_08beee0c;
extern int FUN_088e3e74(Obj *self, int a, int b, int c);
extern int FUN_08ba0d98(Src *a, Src *b);
extern void FUN_088e66cc(int a, int b);
extern void FUN_088f37d0(int a, Arg *p);

void FUN_088e40c0(Obj *self, Src *key, int a2)
{
  if (!FUN_088e3e74(self, 17, a2, DAT_08bb440c))
    return;
  self->src = (int)key;
  self->data = *(W5 *)key;
  Src *def = DAT_08beed14->src;
  if (!FUN_08ba0d98(key, def))
    key = def;
  FUN_088e66cc(DAT_08beee0c, 4);
  int start = (self->x24 - 1) * self->x28;
  unsigned end = start + self->x28;
  if (key->b60 < end)
    end = key->b60;
  int last = end - 1;
  int i;
  for (i = start; i <= last; i++) {
    Arg a;
    a.tag = 1;
    a.val = key->items[i];
    FUN_088f37d0(DAT_08beee0c, &a);
  }
  if (last < start)
    self->b85 = 1;
}
// NEAR ~75 words (8x-word shift): retail hoists the DAT_08bb440c load above the prologue addiu sp; word 0 of the 20-byte lwl/lwr pair is first in retail (last in ours);
// retail's loop keeps a separate byte-offset IV (addu v1,s1,s3) instead of a strength-reduced pointer. -O2 is worse (95 words).
// near miss from lane lbp12a (unreviewed)
