/* LBPMATCH module=EBOOT.BIN start=0x088c6dfc end=0x088c6eb0 symbol=FUN_088c6dfc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_list.h"
#include "lbp/rd2a_object.h"

/* The payload of the owner's list: a record whose +0xa8 member is an object with a vtable. */
struct ListPayload {
  char unk_00[0xa8];
  struct VObject *handler;   /* +0xa8 */
};

struct ListOwner {
  char unk_00[0x58];
  struct ListNode entries;   /* +0x58: list header */
  char unk_64[0x2c];
  char unk_90[0x20];         /* +0x90: sub-object passed to FUN_088bcb3c */
  int unk_b0;                /* cleared here */
};

extern unsigned int DAT_08be84a0;   /* the game heap */
extern void FUN_088050b8();         /* release the payload */
extern void FUN_088bcb3c();
extern void FUN_08adbc24();         /* heap free(heap, ptr, size) */
extern void FUN_08b88fc8();         /* unlink node from its list */
extern void FUN_088c6010();
extern void FUN_088c69bc();
extern void FUN_0894ebcc();

/* Tears down the first entry of the list at +0x58: asks its handler (virtual slot 10) to run with the
   two callbacks, then unlinks and frees the node and releases its payload. */
void FUN_088c6dfc(struct ListOwner *self)
{
  struct ListNode *header = &self->entries;
  struct ListNode *node;
  struct VObject *handler;

  FUN_088bcb3c(self->unk_90);
  self->unk_b0 = 0;
  if (header->next != header) {
    handler = ((struct ListPayload *)header->next->data)->handler;
    (*handler->vtable[10])(handler, 0, 0, FUN_088c69bc, self, FUN_088c6010, FUN_0894ebcc);
    node = header->next;
    FUN_08b88fc8(node);
    if (node->data != 0) {
      FUN_088050b8(node->data);
    }
    FUN_08adbc24(DAT_08be84a0, node, LIST_NODE_SIZE);
  }
}
