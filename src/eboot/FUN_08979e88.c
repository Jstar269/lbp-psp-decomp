/* LBPMATCH module=EBOOT.BIN start=0x08979e88 end=0x08979ef4 symbol=FUN_08979e88 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */
#include "lbp/refmsg.h"

extern void FUN_08970b6c();

typedef struct Forwarder {
  int unk_00;
  int unk_04;
  int unk_08;
  int unk_0c;
  Listener *target;
} Forwarder;

/* Pass the caller's message handle on to the target listener, holding an extra reference while it runs. */
int FUN_08979e88(Forwarder *self,RefMsg **msg_handle)
{
  Listener *target;
  int result;
  ListenerHandleFn handle;
  RefMsg *msg[4];

  target = self->target;
  msg[0] = *msg_handle;
  handle = ((ListenerHandleFn *)target->vtable)[6];
  if (msg[0] != 0) {
    msg[0]->refcount = msg[0]->refcount + 1;
  }
  result = (*handle)(target,msg);
  if (msg[0] != 0) {
    FUN_08970b6c(msg[0]);
  }
  return result;
}
