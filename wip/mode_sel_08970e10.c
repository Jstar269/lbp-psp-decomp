/* LBPMATCH module=EBOOT.BIN start=0x08970e10 end=0x08970e5c symbol=FUN_08970e10 lang=c99 cc=gcc171-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct S { char pad[0x1b8]; int mode; };
extern struct S *FUN_089ecaa8(void);
int FUN_08970e10(void){ int m = FUN_089ecaa8()->mode; int r=7; if (m!=2) { r=16; if (m!=3) { r=2; if (m==1) r=15; } } return r; }
// NEAR 6 words at cc=gcc171-Os (gcc404xs-Os: 13 words). Remaining: the last test (r=2; if (m==1) r=15) is if-converted to xori/movz; retail keeps bne + li delay slot.
// Tried: switch, ternary chain, if/else chains, nested ifs, profiles 404xs-Os/O2, 402x, 410.
// near miss from lane lbp6d (unreviewed)
