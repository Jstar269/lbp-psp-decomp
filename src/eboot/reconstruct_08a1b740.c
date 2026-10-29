/* LBPMATCH module=EBOOT.BIN start=0x08a1b740 end=0x08a1b760 symbol=FUN_08a1b740 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Entry { char pad[64]; float value; };
extern struct Entry DAT_08bf5cac[];
void FUN_08a1b740(float param_1,int param_2)
{
  *(float *)((char *)&DAT_08bf5cac[param_2] + 68) = param_1;
}
