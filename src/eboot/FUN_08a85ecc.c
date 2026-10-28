/* LBPMATCH module=EBOOT.BIN start=0x08a85ecc end=0x08a85f34 symbol=FUN_08a85ecc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
extern int DAT_08bef40c;
extern void FUN_08913dd8();
extern void *FUN_08914a7c();
extern int FUN_08914e94();
extern void *FUN_089f683c();
extern void FUN_089f6c0c();

void FUN_08a85ecc(void)
{
  void *service;
  void *target;
  void *source;
  int value;

  service = FUN_089f683c();
  FUN_089f6c0c(service);
  target = FUN_08914a7c();
  source = FUN_08914a7c();
  value = FUN_08914e94(source, DAT_08bef40c);
  FUN_08913dd8(target, '\0', value, 0x19, 0, '\0', 0x400, 0);
}
