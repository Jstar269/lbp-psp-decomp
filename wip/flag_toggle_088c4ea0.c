/* LBPMATCH module=EBOOT.BIN start=0x088c4ea0 end=0x088c4f14 symbol=FUN_088c4ea0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { char pad[0xd0]; unsigned flags; };
extern unsigned char DAT_08bee64c;
extern unsigned char DAT_08bee64d;
extern struct Obj *DAT_08beee0c;

void FUN_088c4ea0(void)
{
  if (DAT_08bee64d != 0 && DAT_08beee0c != 0) {
    unsigned f = DAT_08beee0c->flags;
    if ((int)(f << 15) < 0) {
      DAT_08beee0c->flags = f | 0x20000;
    } else {
      DAT_08beee0c->flags = f | 0x40000;
    }
  }
  if (DAT_08bee64c == 0) {
    DAT_08bee64c = 1;
    return;
  }
  if (DAT_08bee64d == 0) {
    DAT_08bee64d = 1;
  }
}
// NEAR 2: retail tests bit 16 with 'ext v0,v0,0x10,1; beqzl' (loaded word, value used by the or's), ours 'sll v0,v0,15; bgezl' from (int)(f<<15)<0; (f>>16)&1 and a bitfield read give lui/and (4 words more). No source form tried emits ext. Block order: 'if (!flagA) { flagA=1; return; }' first.
// near miss from lane lbp6c (unreviewed)
