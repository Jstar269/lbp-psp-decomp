/* LBPMATCH module=EBOOT.BIN start=0x0897cddc end=0x0897ce50 symbol=FUN_0897cddc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned char DAT_08bb3758;
extern void FUN_088399bc();
extern void FUN_088cc71c();
extern void FUN_0897633c();
extern void FUN_089d1dfc();
extern void FUN_089d222c();

typedef struct Obj897cddc {
  char pad_00[0x84];
  int unk_84;
  char pad_88[4];
  short *unk_8c;
} Obj897cddc;

/* Eight register arguments. The FUN_088399bc call passes arg_a (fourth slot) and arg_b..arg_e on; the third and
   fourth incoming arguments are not used. */
void FUN_0897cddc(Obj897cddc *self, unsigned int arg_a, unsigned int unused_2, unsigned int unused_3,
                  unsigned int arg_b, unsigned int arg_c, unsigned int arg_d, unsigned int arg_e)
{
  int unk_84;
  unsigned int tmp_a[2];
  int tmp_b[2];

  FUN_088399bc(self->unk_8c,0x10,&DAT_08bb3758,arg_a,arg_b,arg_c,arg_d,arg_e);
  unk_84 = self->unk_84;
  FUN_0897633c(tmp_a,self->unk_8c);
  FUN_089d1dfc(unk_84,tmp_a,0);
  FUN_088cc71c(tmp_b);
  FUN_089d222c(self->unk_84,0);
  return;
}
