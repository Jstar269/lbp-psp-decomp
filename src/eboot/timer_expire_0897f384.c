/* LBPMATCH module=EBOOT.BIN start=0x0897f384 end=0x0897f480 symbol=FUN_0897f384 lang=c99 rodata=0x08bab59c */
/* Hand-written reconstruction from the disassembly (lane lbp4a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef unsigned char uchar;
struct Obj;
struct VT { int pad[13]; void (*fn)(struct Obj *); };
struct Obj { struct VT *vt; char pad[0x6c]; uchar f70; uchar f71; };
struct Owner { char pad0[0x30]; int f30; char pad1[0xc]; float f40[4]; char padx[8]; struct Obj *obj; char pad2[0x64]; float timer; };
extern int DAT_08bef40c;
extern void FUN_08913dd8(void *, int, int, int, int, int, int, int);
extern void *FUN_08914a7c(void);
extern int FUN_08914e94(void *, int);
extern void FUN_0896b048(struct Obj *, int);
extern void FUN_0897db80(struct Owner *, struct Obj *);
extern void FUN_0897f268(float, struct Owner *, int, int, float *);

void FUN_0897f384(float param_1, struct Owner *param_2)
{
  if (0.0f < param_2->timer) {
    float t = param_2->timer - param_1;
    param_2->timer = t;
    if (t <= 0.0f) {
      void *a;
      void *b;
      int r;
      struct Obj *o;
      param_2->timer = 0.0f;
      a = FUN_08914a7c();
      b = FUN_08914a7c();
      r = FUN_08914e94(b, DAT_08bef40c);
      FUN_08913dd8(a, 0, r, 10, 0, 0, 0x400, 0);
      param_2->obj->vt->fn(param_2->obj);
      FUN_0897db80(param_2, param_2->obj);
      o = param_2->obj;
      o->f71 = 1;
      o->f70 = 1;
      FUN_0896b048(o, 1);
      FUN_0897f268(1.0f, param_2, 0, param_2->f30, param_2->f40);
    }
  }
}
