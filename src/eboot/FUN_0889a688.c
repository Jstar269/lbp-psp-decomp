/* LBPMATCH module=EBOOT.BIN start=0x0889a688 end=0x0889a700 symbol=FUN_0889a688 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int *FUN_0889bc4c();
extern void FUN_0889bca4();
extern void FUN_0889bd00();

/* A request record: kind 0 or 1 selects which of the two handlers gets the argument. */
struct Request {
  int kind;
  int unk_04;
  int arg;
};

void FUN_0889a688(int unused,struct Request *request)
{
  int *target;

  if (request != (struct Request *)0x0) {
    if (request->kind == 0) {
      target = FUN_0889bc4c();
      FUN_0889bd00(target,request->arg);
      return;
    }
    if (request->kind == 1) {
      target = FUN_0889bc4c();
      FUN_0889bca4(target,request->arg);
      return;
    }
  }
  return;
}
