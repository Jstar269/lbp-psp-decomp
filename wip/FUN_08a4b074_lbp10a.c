/* LBPMATCH module=EBOOT.BIN start=0x08a4b074 end=0x08a4b120 symbol=FUN_08a4b074 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct W5 { int w[5]; } __attribute__((packed)) W5;
typedef struct W5A { int w[5]; } W5A;
typedef struct Work { long long align; char b[0x60]; } Work;

extern void FUN_08af767c(Work *w);
extern void FUN_08af72b0(Work *w, void *src, int n);
extern void FUN_08af7480(Work *w, W5A *out);

void FUN_08a4b074(char *self, W5 *out)
{
  Work w;
  W5A tmp;
  FUN_08af767c(&w);
  FUN_08af72b0(&w, self + 64, 20);
  FUN_08af7480(&w, &tmp);
  *out = *(W5 *)&tmp;
}
// NEAR: 8 words differ: register allocation only (retail loads word 0 into v1 and word 1 into v0; ours the reverse). Local temp of a plain 20-byte struct
// read through a packed-struct pointer gives retail frame layout (temp at sp+0, 8-aligned work object at sp+24) and lwl/lwr from the stack; assigned to *out (packed) gives swl/swr.
// Tried: memcpy, aligned(4) local (becomes lw), pointer temp, declaration order.
// near miss from lane lbp10a (unreviewed)
