/* LBPMATCH module=EBOOT.BIN start=0x088e34f4 end=0x088e3540 symbol=FUN_088e34f4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
extern int FUN_088e327c();   /* (self, mode, value, flag, arg5..arg8): non-zero on success */
extern void FUN_088e28e8();  /* (self, self) */

/* Calls FUN_088e327c in mode 0 with the stack arguments passed through; on success runs FUN_088e28e8.
   The third and fourth parameters are not used (they only occupy argument slots). */
void FUN_088e34f4(int *self, int value, int unused_3, int unused_4, int arg5, int arg6, int arg7, int arg8)
{
  if (FUN_088e327c(self, 0, value, '\0', arg5, arg6, arg7, arg8) != 0) {
    FUN_088e28e8(self, self);
  }
}
