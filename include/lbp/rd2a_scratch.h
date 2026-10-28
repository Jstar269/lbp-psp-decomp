#ifndef LBP_RD2A_SCRATCH_H
#define LBP_RD2A_SCRATCH_H

#include "lbp/rd2a_object.h"

/* 32-byte stack object built by FUN_08921788, filled by FUN_089218fc and torn down by FUN_08921a38. */
struct ScratchObject {
  int unk[8];
};

/* Object shared by the three "record then dispatch" handlers: vtable at +0, a flag byte at +0x10
   and a target object at +0xa8. */
struct RecordingHost {
  void (**vtable)();
  char unk_04[0xc];
  unsigned char recorded;       /* +0x10: set to 1 after the record was applied */
  char unk_11[0x97];
  void *target;                 /* +0xa8 */
};

#endif
