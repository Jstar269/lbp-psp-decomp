/* LBPMATCH module=EBOOT.BIN start=0x0895eb04 end=0x0895eb74 symbol=FUN_0895eb04 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x60];
  unsigned int unk_60[4];   /* +0x60: 16-byte value */
};

extern int DAT_08beed14;
extern void FUN_088d7a1c(int arg0, int arg1, unsigned int *vec);
extern void FUN_088d9460(int arg0, unsigned int id, unsigned int *vec);
extern int FUN_088da790(int arg0, unsigned int id);

/* The low 16 bits of `packed` select the item; FUN_088d9460 fills the 16-byte value at +0x60, which is then passed to
   FUN_088d7a1c. */
void FUN_0895eb04(struct Obj *self, unsigned int packed)
{
  int handle;

  handle = FUN_088da790(DAT_08beed14, packed & 0xffff);
  FUN_088d9460(DAT_08beed14, packed & 0xffff, self->unk_60);
  FUN_088d7a1c(DAT_08beed14, handle, self->unk_60);
  return;
}
