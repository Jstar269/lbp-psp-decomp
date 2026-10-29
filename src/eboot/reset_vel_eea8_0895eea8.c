/* LBPMATCH module=EBOOT.BIN start=0x0895eea8 end=0x0895eef0 symbol=FUN_0895eea8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern float DAT_08bb823c;
extern float DAT_08bb8240;
struct O { char pad0[8]; unsigned char f8; char pad1[0x2f]; float f38; int f3c; int pad40; int f44; int f48; int f4c; char pad50[0x20]; int f70; };
void FUN_0895eea8(struct O *o, unsigned char flag)
{
  if (o->f8 == 0) {
    o->f70 = 3;
    o->f38 = flag ? DAT_08bb823c : DAT_08bb8240;
    o->f3c = 0;
    o->f44 = 0;
    o->f4c = 0;
    o->f48 = 0;
  }
}
