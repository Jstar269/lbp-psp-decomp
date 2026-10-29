/* LBPMATCH module=EBOOT.BIN start=0x08a3df6c end=0x08a3df8c symbol=FUN_08a3df6c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern float DAT_08bac1bc; extern void *DAT_08bdc1dc;
extern void FUN_08a3dd0c(float, float, int, int, void *, void *, int);
void FUN_08a3df6c(int a, int b) { FUN_08a3dd0c(0.0f, DAT_08bac1bc, a, b, DAT_08bdc1dc, 0, 0); }

// Four words differ in global load scheduling; Os and O2 tried.
// near miss from lane lbp15b (unreviewed)
