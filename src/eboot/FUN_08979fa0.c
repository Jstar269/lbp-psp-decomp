/* LBPMATCH module=EBOOT.BIN start=0x08979fa0 end=0x0897a04c symbol=FUN_08979fa0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */
#include "lbp/refmsg.h"

extern void FUN_08970b6c();
extern RefMsg * FUN_08979514();

/* Send message 0x4a3c (carrying the dispatcher's sender) to every listener in turn, until one returns 0. */
void FUN_08979fa0(Dispatcher *dispatcher)
{
  int keep_going;
  ListenerHandleFn handle;
  Listener *listener;
  RefMsg *built[3];   /* FUN_08979514 stores the new message in built[0] */
  RefMsg *msg;

  FUN_08979514(built,0x4a3c,&dispatcher->sender);
  for (listener = dispatcher->first; listener != 0; listener = listener->next) {
    msg = built[0];
    handle = ((ListenerHandleFn *)listener->vtable)[2];
    if (built[0] != 0) {
      built[0]->refcount = built[0]->refcount + 1;   /* each listener gets its own reference */
    }
    keep_going = (*handle)(listener,&msg);
    if (msg != 0) {
      FUN_08970b6c(msg);
    }
    if (keep_going == 0) break;
  }
  if (built[0] != 0) {
    FUN_08970b6c(built[0]);
  }
  return;
}
