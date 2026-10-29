/* LBPMATCH module=EBOOT.BIN start=0x08890b1c end=0x08890b94 symbol=FUN_08890b1c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
extern char DAT_08bb0ff8, DAT_08bef8f4, DAT_08bedae0;
extern int DAT_08bedd04;
extern void FUN_08ad3088(void *), FUN_08890410(void *, int, int), FUN_08ad2810(void *), FUN_0888b898(void *), FUN_08890a48(void *), FUN_08a9e0cc(void *);
void FUN_08890b1c(char *p) {
 *(void **)p = &DAT_08bb0ff8;
 FUN_08ad3088(&DAT_08bef8f4);
 FUN_08890410(&DAT_08bedae0, 0, 0);
 FUN_08ad2810(&DAT_08bef8f4);
 FUN_0888b898(p + 44);
 FUN_08890a48(p);
 DAT_08bedd04 = 0;
 FUN_08a9e0cc(p);
}
// Two prologue instructions swapped; Os and O2 both differ by 2 words.
// near miss from lane lbp13a (unreviewed)
