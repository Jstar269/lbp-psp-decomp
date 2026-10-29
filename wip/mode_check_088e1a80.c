/* LBPMATCH module=EBOOT.BIN start=0x088e1a80 end=0x088e1b10 symbol=FUN_088e1a80 lang=c99  */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Info { int pad0; unsigned short id; };
struct Cur { char pad[0x18]; struct Info *info; };
struct State { int pad0; int mode; };
struct Mgr { char pad[8]; int kind; };
extern struct Mgr *DAT_08beed14;
extern struct Cur *FUN_088d7f9c(void);
extern struct State *FUN_088dc4b4(struct Mgr *m);

int FUN_088e1a80(void)
{
  int r;
  if (FUN_088d7f9c()->info->id == 0xffff) r = 0;
  else if (FUN_088dc4b4(DAT_08beed14)->mode == 2) r = 1;
  else if (FUN_088dc4b4(DAT_08beed14)->mode != 1) r = 0;
  else if (DAT_08beed14->kind == 1 && FUN_088dc4b4(DAT_08beed14)->mode == 1) r = 0;
  else r = 1;
  return r;
}
// NEAR 13: logic right (38 vs 36 words); retail tail is 'bne s0,1 -> li v0,1; beql v0,s0 -> move v0,zero in delay; li v0,1' with one epilogue; ours emits bnel + j + two li/move blocks. Tried if/else ladders, ternaries, returns, O2 (worse).
// near miss from lane lbp6c (unreviewed)
