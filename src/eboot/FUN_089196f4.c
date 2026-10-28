/* LBPMATCH module=EBOOT.BIN start=0x089196f4 end=0x08919730 symbol=FUN_089196f4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Dat089ecaa8 {
  char pad_00[0x148];
  int unk_148;
};

struct Request {
  char pad_00[0x10];
  int *out;   /* +0x10: where the looked-up value is stored */
};

extern int DAT_08bef418;
extern int FUN_08914e94(int arg0, int arg1);
extern struct Dat089ecaa8 *FUN_089ecaa8(void);

void FUN_089196f4(struct Request *request)
{
  struct Dat089ecaa8 *instance;
  int value;

  instance = FUN_089ecaa8();
  value = FUN_08914e94(instance->unk_148, DAT_08bef418);
  *request->out = value;
  return;
}
