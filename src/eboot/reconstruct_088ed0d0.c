/* LBPMATCH module=EBOOT.BIN start=0x088ed0d0 end=0x088ed1e8 symbol=FUN_088ed0d0 lang=c99 cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp6a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { struct Node *next; struct Node *prev; };
struct Obj {
  char pad0[0x40]; int handle; int state; char pad1[0xa0 - 0x48]; int f_a0;
  char pad2[0x130 - 0xa4]; struct Node list16; struct Node list28;
};
extern struct Node **FUN_088827c0(void);
extern void *DAT_08be84a0;
extern void FUN_08849d5c(struct Node *);
extern int FUN_0887f414(int, int);
extern void FUN_088e8554(struct Obj *);
extern void FUN_088ed040(struct Obj *, int);
extern void FUN_08adbc24(void *, void *, int);
void FUN_088ed0d0(struct Obj *obj, unsigned char flag)
{
  struct Node **pp;
  struct Node *n, *next, *end;
  if ((unsigned int)(obj->state - 0x12) < 3) {
    obj->state = 0x19;
    FUN_0887f414(obj->handle, 4);
    pp = FUN_088827c0();
    FUN_08849d5c(*pp);
    if (obj->f_a0 != 0) obj->f_a0 = 0;
    end = &obj->list28;
    n = end->next;
    while (n != end) {
      next = n->next;
      FUN_08adbc24(DAT_08be84a0, n, 0x1c);
      n = next;
    }
    end->next = end;
    end->prev = end;
    end = &obj->list16;
    n = end->next;
    while (n != end) {
      next = n->next;
      FUN_08adbc24(DAT_08be84a0, n, 0x10);
      n = next;
    }
    end->next = end;
    end->prev = end;
    if (flag == 0) {
      FUN_088ed040(obj, 0);
      FUN_088e8554(obj);
      return;
    }
  }
}
