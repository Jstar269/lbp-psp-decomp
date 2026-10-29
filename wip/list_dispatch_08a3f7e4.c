/* LBPMATCH module=EBOOT.BIN start=0x08a3f7e4 end=0x08a3f894 symbol=FUN_08a3f7e4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); NEAR MISS, not exact. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
extern int DAT_08bef408;
extern char *DAT_08bf7304;
extern void FUN_08913dd8(void *, int, int, int, int, int, int, int);
extern void *FUN_08914a7c();
extern int FUN_08914e94(void *, int);
extern int FUN_08a50fbc();
struct VT { void *p0, *p1; void (*f)(struct Obj *); };
struct Obj { struct VT *vt; };
struct Owner { char pad[8]; struct Obj *obj; };
struct Node { struct Node *next; struct Owner *owner; };
struct S { int pad; struct Node head; };
void FUN_08a3f7e4(struct S *s)
{
  struct Node *n = s->head.next;
  int count = 0;
  if (n != &s->head) {
    do {
      n = n->next;
      count++;
    } while (n != &s->head);
    if (count != 0) {
      struct Obj *o = s->head.owner->obj;
      o->vt->f(o);
    }
  }
  {
    void *a = FUN_08914a7c();
    void *b = FUN_08914a7c();
    int r = FUN_08914e94(b, DAT_08bef408);
    FUN_08913dd8(a, 0, r, 3, 0, 0, 0x400, 0);
  }
  FUN_08a50fbc();
  DAT_08bf7304[0x96] = 0;
}

// 10 words off: retail keeps the list head in a0 (addiu a0,a0,4 reuses the parameter register; lw v0,4(a0); lw a0,8(v0); lw v1,0(a0); lw v0,8(v1)), ours head in a1 and v0 chains; looks like -O2 register choice but O2 reorders the blocks (64 off).
// list size loop + virtual call with this argument done; only allocation differs
// near miss from lane lbp4d (unreviewed)
