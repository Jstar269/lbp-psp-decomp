/* LBPMATCH module=EBOOT.BIN start=0x08957410 end=0x08957444 symbol=FUN_08957410 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15a, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08befa50; extern void FUN_08956d6c(void);
void FUN_08957410(char *p) { void **q=(void **)(p-4); DAT_08befa50=0; ((void (*)(void *, void *, int, int, int))(*(void ***)q)[7])(q,FUN_08956d6c,0,0,1); }
// Shared entry thunk and body; ordinary C folds the adjustment.
// near miss from lane lbp15a (unreviewed)
