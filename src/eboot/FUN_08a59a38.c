/* LBPMATCH module=EBOOT.BIN start=0x08a59a38 end=0x08a59ae0 symbol=FUN_08a59a38 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int FUN_08a1d1bc();
extern void FUN_08a9bff8();
extern unsigned int * FUN_08a9d390();

typedef struct Provider Provider;
typedef struct ProviderVtable {
  void *slots_00[25];
  int (*slot_64)(Provider *self);   /* returns the handle passed to FUN_08a1d1bc */
} ProviderVtable;
struct Provider {
  ProviderVtable *vtable;
};

typedef struct Obj8a59a38 {
  char pad_00[0x148];
  int result_a;
  int result_b;
} Obj8a59a38;

void FUN_08a59a38(Obj8a59a38 *self, Provider *provider, int key_a, int key_b)
{
  int handle;
  int result;
  unsigned int tmp_b[6];   /* 24-byte temporaries built from each key (FUN_08a9d390), then passed to FUN_08a9bff8 */
  unsigned int tmp_a[6];

  handle = (*provider->vtable->slot_64)(provider);
  FUN_08a9d390(tmp_a,key_a);
  FUN_08a9bff8((int)tmp_a);
  result = FUN_08a1d1bc(handle,key_a);
  self->result_a = result;
  FUN_08a9d390(tmp_b,key_b);
  FUN_08a9bff8((int)tmp_b);
  handle = FUN_08a1d1bc(handle,key_b);
  self->result_b = handle;
  return;
}
