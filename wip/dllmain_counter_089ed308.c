/* LBPMATCH module=EBOOT.BIN start=0x089ed308 end=0x089ed3d0 symbol=FUN_089ed308 lang=c99 rodata=0x08bab598 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct St { void *p; int a, b, c, d; unsigned char flag; };
extern unsigned long long DAT_08be83e8;
extern struct St DAT_08be8418;
extern float DAT_08bf36c4;
extern void FUN_08adb8a4(void *);
void FUN_089ed308(int reason, int id)
{
  switch (reason) {
  case 1:
    if (id == 0xffff) {
      DAT_08be83e8++;
      DAT_08bf36c4 = -3.4028235e38f;
      if (DAT_08be83e8 == 1) {
        DAT_08be8418.p = 0;
        DAT_08be8418.flag = 0;
        DAT_08be8418.a = 0;
        DAT_08be8418.b = 0;
        DAT_08be8418.c = 0;
        DAT_08be8418.d = 0;
      }
    }
    break;
  case 0:
    if (id == 0xffff) {
      DAT_08be83e8--;
      if (DAT_08be83e8 == 0 && DAT_08be8418.p != 0)
        FUN_08adb8a4(DAT_08be8418.p);
    }
    break;
  }
}
// NEAR ~48 words: retail tests reason==1 first (li v0,1; beq -> case-1 block placed after case 0), then bnez reason -> return; case-0 block falls through; tried if/else both orders, switch both orders, O2.
// near miss from lane lbp11d (unreviewed)
