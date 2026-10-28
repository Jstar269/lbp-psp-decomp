/* LBPMATCH module=EBOOT.BIN start=0x088bf7a4 end=0x088bf83c symbol=FUN_088bf7a4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned int DAT_08bef3f0;
extern unsigned int DAT_08bf03b8;
extern void FUN_088050b8();
extern void FUN_0883c3b4();
extern unsigned int * FUN_08914a7c();
extern void FUN_08914c70();
extern void FUN_0896f07c();
extern void FUN_08a2d0d0();

typedef struct Owned Owned;
typedef struct OwnedVtable {
  void *slot_00;
  void (*slot_04)(Owned *self);   /* called on the member before it is cleared */
} OwnedVtable;
struct Owned {
  OwnedVtable *vtable;
};

typedef struct Obj88bf7a4 {
  char pad_00[0x14];
  void *unk_14;
  char unk_18[0x18];   /* sub-object, passed by address to FUN_0883c3b4 */
  Owned *unk_30;
} Obj88bf7a4;

void FUN_088bf7a4(Obj88bf7a4 *self)
{
  Owned *owned;
  void *old;
  unsigned int *result;

  if (self->unk_30 != 0) {
    FUN_0896f07c(DAT_08bf03b8,5,self->unk_30);
    owned = self->unk_30;
    if (owned != 0) {
      (*owned->vtable->slot_04)(owned);
    }
    self->unk_30 = 0;
  }
  old = self->unk_14;
  self->unk_14 = 0;
  if (old != 0) {
    FUN_088050b8(old);
  }
  FUN_0883c3b4(self->unk_18);
  FUN_08a2d0d0(8);
  result = FUN_08914a7c();
  FUN_08914c70((int)result,DAT_08bef3f0);
  return;
}
