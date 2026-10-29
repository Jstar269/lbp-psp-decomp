/* LBPMATCH module=EBOOT.BIN start=0x08a1d41c end=0x08a1d450 symbol=FUN_08a1d41c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 1 word(s) differ; names and types await human review. */
typedef unsigned int undefined4;
struct Elem { char pad[0x18]; undefined4 f18; undefined4 f1c; char pad2[0x4]; };
struct Obj { char pad[0xc]; struct Elem *elems; char pad2[0xc]; int count; };

void FUN_08a1d41c(struct Obj *param_1,int param_2,undefined4 *param_3)
{
  if (param_1->count > param_2) {
    param_1->elems[param_2].f18 = *param_3;
  }
}
// differs: final addu operand order (retail v0=base,a0=offset; ours offset,base)
// tried: count>i, byte-pointer arithmetic, hoisting elems, offset local, accessors (12 variants)
// near miss from lane lbp3a (unreviewed)
