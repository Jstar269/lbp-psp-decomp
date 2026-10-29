/* LBPMATCH module=EBOOT.BIN start=0x088d7a48 end=0x088d7a84 symbol=FUN_088d7a48 lang=c99 cc=gcc410-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct R { char pad0[0x18c]; int *tab; char pad1[0x2c]; int recs; unsigned n; };
int FUN_088d7a48(struct R *r, unsigned i)
{
  if (i < r->n)
    return r->recs + i * 0x1cc;
  return r->tab[i - r->n];
}

// NEAR 5 words at cc=gcc410-Os: retail uses mtlo/madd (multiply-accumulate) for recs + i*0x1cc; gcc410 gives mult/mflo/addu; gcc404xs/gcc402x expand i*460 as shifts (20 words).
// Tried: pointer-to-struct (sizeof 460), int/unsigned types, local n, reversed compare, O2 profiles.
// near miss from lane lbp6d (unreviewed)
