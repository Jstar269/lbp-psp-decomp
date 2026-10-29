/* LBPMATCH module=EBOOT.BIN start=0x088e7a78 end=0x088e7abc symbol=FUN_088e7a78 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): calls take the constant 15; exact match verified; names and types await human review. */
extern void FUN_088e79f0(int);
extern void FUN_089f19c0(int);
extern void FUN_089f1a64(int);
extern int FUN_08a50fbc(void);
extern void FUN_08a51f94(int);

void FUN_088e7a78(int p)
{
  FUN_089f1a64(15);
  FUN_088e79f0(p + 0x14);
  FUN_08a51f94(FUN_08a50fbc());
  FUN_089f19c0(15);
}
