/* LBPMATCH module=EBOOT.BIN start=0x089786f4 end=0x089787dc symbol=FUN_089786f4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp7a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ref { void (**vtable)(struct Ref *); int count; } Ref;
typedef struct Small { int a; short b; unsigned short count; } Small;
typedef struct Item { char pad[48]; int field; } Item;
typedef struct Obj { char pad[20]; void *field; Item **items; } Obj;
extern void FUN_0896c00c(void *, Item *, Small **, Ref **);
extern void FUN_08970b6c(Small *);
extern void FUN_089757c0(int);
extern void FUN_08adb8a4(Ref *);
void FUN_089786f4(Obj *o, int index, Small **a, Ref **b) {
 Ref *y; Small *x;
 void *field = o->field; Item *item = o->items[index];
 x = *a;
 if (x) ++x->count;
 y = *b;
 if (y) ++y->count;
 FUN_0896c00c(field,item,&x,&y);
 { Ref *r = y; if (r && --r->count == 0) { r->vtable[0](r); FUN_08adb8a4(r); } }
 if (x) FUN_08970b6c(x);
 FUN_089757c0(o->items[index]->field);
}
