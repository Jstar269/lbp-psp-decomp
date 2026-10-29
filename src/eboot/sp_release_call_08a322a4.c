/* LBPMATCH module=EBOOT.BIN start=0x08a322a4 end=0x08a3239c symbol=FUN_08a322a4 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/sp_release_call_08a209d0.c (lbpclone.py tag c17): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the always-true test of a function address is kept by declaring that function weak (retail compares the constant against zero at run time). */
typedef struct Obj { void **vtable; } Obj;
typedef struct Root { char pad[156]; Obj sub; } Root;
typedef struct Pair { Obj *ptr; int *count; } Pair;
extern char DAT_08bef8f4[];
extern char *DAT_08be84ac;
extern Root *FUN_089ecaa8(void);
extern void FUN_08804f34(void) __attribute__((weak));
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);
extern void FUN_08adb8a4(void *);
extern void FUN_08adbc24(void *, void *, unsigned int);

void FUN_08a322a4(int unused, int arg)
{
  Pair p;
  Root *r = FUN_089ecaa8();
  int *cnt;
  int c;

  ((void (*)(Pair *, Obj *))r->sub.vtable[14])(&p, &r->sub);
  if (p.ptr != 0 && FUN_08804f34 != 0) {
    ((void (*)(Obj *, int))p.ptr->vtable[12])(p.ptr, arg);
  }
  cnt = p.count;
  if (cnt != 0) {
    FUN_08ad3088(DAT_08bef8f4);
    c = --*cnt;
    FUN_08ad2810(DAT_08bef8f4);
    if (c == 0) {
      Obj *o = p.ptr;
      if (o != 0) {
        ((void (*)(Obj *))o->vtable[0])(o);
        FUN_08adb8a4(o);
      }
      {
        char *heap = DAT_08be84ac;
        int *cnt2 = p.count;
        FUN_08ad3088(heap + 32);
        FUN_08adbc24(heap, cnt2, 4);
        FUN_08ad2810(heap + 32);
      }
    }
  }
}
