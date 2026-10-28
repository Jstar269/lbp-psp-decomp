/* LBPMATCH module=EBOOT.BIN start=0x08806440 end=0x088064f4 symbol=FUN_08806440 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned int FUN_0880639c();
extern unsigned char FUN_08950f34();
extern int * FUN_08951278();
extern int FUN_089f19c0();
extern void FUN_089f1a64();

typedef struct Created Created;
typedef struct CreatedVtable {
  void *slots_00[11];
  void (*slot_2c)(Created *self);
  void (*slot_30)(Created *self);
} CreatedVtable;
struct Created {
  CreatedVtable *vtable;
};

Created * FUN_08806440(unsigned int arg_a, unsigned int arg_b, unsigned int arg_c, int arg_d)
{
  unsigned char old_setting;
  Created *created;
  unsigned int args_b[3];
  unsigned int args_a;

  FUN_089f1a64(0x1a);   /* paired with FUN_089f19c0(0x1a) below */
  args_a = FUN_0880639c(arg_a,arg_c);
  args_b[0] = arg_b;
  old_setting = FUN_08950f34(0);   /* set to 0, restored below */
  created = (Created *)FUN_08951278(&args_a,args_b,arg_d);
  (*created->vtable->slot_2c)(created);
  (*created->vtable->slot_30)(created);
  FUN_08950f34(old_setting);
  FUN_089f19c0(0x1a);
  return created;
}
