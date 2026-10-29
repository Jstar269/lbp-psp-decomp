/* LBPMATCH module=EBOOT.BIN start=0x0898ce98 end=0x0898cfb4 symbol=FUN_0898ce98 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Q { int pad[10]; int **arr; short idx; };
struct O { int pad[5]; Q *q; int pad2[2]; int state; };
extern int DAT_08bedb54;
extern "C" bool FUN_0884224c(int, int);
extern "C" void FUN_0896b048(int *, int);
extern "C" void FUN_0898ce98(O *o)
{
  if (o->state == 1) {
    bool b = !FUN_0884224c(DAT_08bedb54, 0x19);
    FUN_0896b048(o->q->arr[6 - o->q->idx], !b);
    FUN_0896b048(o->q->arr[7 - o->q->idx], b);
    b = !FUN_0884224c(DAT_08bedb54, 0x20);
    FUN_0896b048(o->q->arr[4 - o->q->idx], !b);
    FUN_0896b048(o->q->arr[5 - o->q->idx], b);
  }
}
