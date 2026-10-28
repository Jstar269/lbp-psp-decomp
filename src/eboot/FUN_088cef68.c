/* LBPMATCH module=EBOOT.BIN start=0x088cef68 end=0x088cef78 symbol=FUN_088cef68 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_088ceb6c.c (lbpclone.py tag r-rd4b): addresses substituted; exact match verified; names and types await human review. */
#include "lbp/rd4b_ptrlist.h"

extern struct PtrListHolder *DAT_08beee0c;
extern void FUN_088e6494(struct PtrListHolder *target, int arg);

void FUN_088cef68(void)
{
  FUN_088e6494(DAT_08beee0c, 0);
  return;
}
