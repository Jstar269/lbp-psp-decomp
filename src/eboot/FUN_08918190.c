/* LBPMATCH module=EBOOT.BIN start=0x08918190 end=0x089181c8 symbol=FUN_08918190 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
extern int FUN_08ac96c0();   /* (obj, arg3, arg4, arg5, short6, short7): result is stored through out */

/* Thin wrapper: forwards six of its arguments to FUN_08ac96c0 and stores the result in *out.
   unused_1, unused_8 and unused_9 are not used (they occupy argument slots). */
void FUN_08918190(int unused_1, int *obj, int arg3, int arg4, int arg5, short short6, short short7,
                  int unused_8, int unused_9, int *out)
{
  *out = FUN_08ac96c0(obj, arg3, arg4, arg5, short6, short7);
}
