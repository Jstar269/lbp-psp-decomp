/* LBPMATCH module=EBOOT.BIN start=0x089e5b3c end=0x089e5b6c symbol=FUN_089e5b3c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern unsigned int FUN_0899abe8();

/* Record whose words at +4, +0xc and +0x1c are forwarded. */
struct Params {
  char unk_00[4];
  unsigned int unk_04;
  char unk_08[4];
  unsigned int unk_0c;
  char unk_10[0xc];
  unsigned int unk_1c;
};

struct HasParams {
  char unk_00[0xa8];
  struct Params *params;
};

struct Forwarder {
  char unk_00[0x310];
  int unk_310;
};

void FUN_089e5b3c(struct Forwarder *self,struct HasParams **source)
{
  struct Params *params;

  params = (*source)->params;
  FUN_0899abe8(self->unk_310,params->unk_04,params->unk_0c,params->unk_1c);
  return;
}
