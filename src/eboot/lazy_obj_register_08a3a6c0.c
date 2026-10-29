/* LBPMATCH module=EBOOT.BIN start=0x08a3a6c0 end=0x08a3a794 symbol=FUN_08a3a6c0 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unit is -O2. */
typedef unsigned int uint;
typedef unsigned char uchar;
struct VT { int pad[23]; uint (*fn)(void *); };
struct Obj { struct VT *vt; };
struct Owner { int pad[0x36]; int key[3]; struct Obj *obj; };
extern int FUN_08a34688(struct Owner *, uchar);
extern int FUN_08a50fbc(void);
extern struct Obj *FUN_08a52bb8(int, int *);
extern void FUN_08a8e400(int, uint, struct Owner *);

int FUN_08a3a6c0(struct Owner *param_1, uchar param_2)
{
  int r = FUN_08a34688(param_1, param_2);
  struct Obj *o = param_1->obj;
  if (o == 0) {
    o = FUN_08a52bb8(FUN_08a50fbc(), param_1->key);
    param_1->obj = o;
  }
  uint id = o->vt->fn(o);
  FUN_08a8e400(FUN_08a50fbc() + 0xb7c, id, param_1);
  return r;
}
