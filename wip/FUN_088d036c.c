/* LBPMATCH module=EBOOT.BIN start=0x088d036c end=0x088d0438 symbol=FUN_088d036c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { char pad[0xd0]; unsigned int low : 6; unsigned int bit6 : 1; unsigned int rest : 25; };
struct Src { char pad[0x1fc]; unsigned int flags; };
extern struct Obj *DAT_08beee0c;
extern struct Src *DAT_08beed14;
extern void FUN_088d0208(void);
extern void FUN_088e68a0(struct Obj *, int, int);
extern int FUN_088f6650(struct Obj *, void (*)(void));
void FUN_088d036c(void)
{
  FUN_088e68a0(DAT_08beee0c, 0, 26);
  FUN_088e68a0(DAT_08beee0c, 0, 27);
  FUN_088e68a0(DAT_08beee0c, 0, 28);
  FUN_088e68a0(DAT_08beee0c, 0, 29);
  FUN_088e68a0(DAT_08beee0c, 0, 30);
  if (FUN_088f6650(DAT_08beee0c, FUN_088d036c) != 0) {
    FUN_088e68a0(DAT_08beee0c, 1, 40);
    return;
  }
  FUN_088e68a0(DAT_08beee0c, 0, 40);
  DAT_08beee0c->bit6 = (DAT_08beed14->flags & 7) >> 2;
  FUN_088d0208();
}
// 8 words differ (53 vs 51): retail 'ext v0,v0,2,1; ins v1,v0,6,1' (ins from a REGISTER); ours sll+ins zero+or. The compiler never emits ins rd,rs,pos,len (tested a plain bit-field store of an unsigned x: andi+sll+ins zero+or).
// near miss from lane lbp6a (unreviewed)
