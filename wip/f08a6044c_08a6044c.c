/* LBPMATCH module=EBOOT.BIN start=0x08a6044c end=0x08a60480 symbol=FUN_08a6044c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp15a, Codex GPT-6); exact match verified; names and types await human review. */
extern float DAT_08bc0fcc;
void FUN_08a6044c(char *p, float f) { if (DAT_08bc0fcc * *(float *)(p+592) < f) (*(void (**)(void *))(*(char **)p+292))(p); }


// O2 is two words off: the two float loads are scheduled in reverse order; Os differs in control flow.
// near miss from lane lbp15a (unreviewed)
