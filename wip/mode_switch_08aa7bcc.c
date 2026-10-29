/* LBPMATCH module=EBOOT.BIN start=0x08aa7bcc end=0x08aa7c78 symbol=FUN_08aa7bcc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Obj { char pad[28]; unsigned flags; } Obj;
extern void FUN_08aa4aa4(Obj *, int);
extern void FUN_08aa7b74(Obj *, int);
extern void FUN_08aa47d4(Obj *, int);
extern void FUN_08aa76c4(Obj *, int);
void FUN_08aa7bcc(Obj *o, unsigned mode)
{
  if (mode == (o->flags & 0x38))
    return;
  switch (mode) {
  case 8:
  case 0x18:
    FUN_08aa4aa4(o, 0);
    FUN_08aa7b74(o, 0);
    break;
  case 0x10:
  case 0x20:
    FUN_08aa47d4(o, 0);
    FUN_08aa76c4(o, 0);
    break;
  }
}
// NEAR ~30 words (45/43): control flow matches but retail passes a1 as `li a1,0` (addiu) in the jal delay slot with a0 NOT reloaded (move a0,s0 only before the tail call), ours emits move a1,zero + move a0,s0 before each call.
// tried: int/char/short/_Bool/void*/long long second arg, (int) first arg, goto ladder from pseudocode, O2, gcc402x/410/171.
// near miss from lane lbp8c (unreviewed)
