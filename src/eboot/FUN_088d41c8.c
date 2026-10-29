/* LBPMATCH module=EBOOT.BIN start=0x088d41c8 end=0x088d4238 symbol=FUN_088d41c8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. Packed-struct copy of 20 bytes (lwl/lwr + sw); the source pointer is declared int in the context, so the key stores force its reload. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
typedef struct Src { W5 k; char pad14[58 - 20]; unsigned short s58; } Src;
typedef struct Ctx { char pad[452]; int src; } Ctx;
typedef struct Obj {
  unsigned flags;
  char pad4[28];
  int x20;
  int x24;
  char pad28[0x3c - 0x28];
  W5 key;
  char pad50[126 - 0x50];
  unsigned short s126;
} Obj;
extern Ctx *DAT_08beed14;

void FUN_088d41c8(Obj *self, int a)
{
  self->key = ((Src *)DAT_08beed14->src)->k;
  self->s126 = ((Src *)DAT_08beed14->src)->s58;
  self->x24 = a;
  self->x20 = 2;
  self->flags |= 1;
}
