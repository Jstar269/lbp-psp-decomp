/* LBPMATCH module=EBOOT.BIN start=0x08a26bec end=0x08a26cac symbol=FUN_08a26bec lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 7 word(s) differ; names and types await human review. */
typedef unsigned char uchar;
typedef unsigned int undefined4;

extern void FUN_08a1dd1c();
extern void FUN_08a26210();
extern void FUN_08a26784();

struct Sub { char pad[0x28]; int count; };
struct Obj;
struct Vt { void *pad[3]; struct Sub *(*get)(struct Obj *); };
struct Obj { struct Vt *vt; };

void FUN_08a26bec(struct Obj **param_1,int *param_2,int *param_3,uchar param_4)
{
  struct Sub *s;

  if (param_3 != (int *)0x0) {
    FUN_08a1dd1c(param_3);
  }
  s = (*param_1)->vt->get(*param_1);
  if (0 < s->count) {
    FUN_08a26210(param_1,param_2,param_3);
    return;
  }
  s = (*param_1)->vt->get(*param_1);
  FUN_08a26784(s,param_2,param_3,param_4);
  return;
}
// differs: virtual-call sequence register choice (retail loads the vptr into v1 before 'move a0,v0' and keeps the count in v1; ours reuses v0)
// fixed: param_4 is unsigned char (andi at entry); tried C and C++ virtual forms, local object temps
// near miss from lane lbp3a (unreviewed)
