/* LBPMATCH module=EBOOT.BIN start=0x0888732c end=0x088873a0 symbol=FUN_0888732c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char DAT_08bb0c78,DAT_08bef8f4,DAT_08bedbe0; extern int DAT_08bedc38;
extern void FUN_08ad3088(void *),FUN_088855c4(void *,int,int),FUN_08ad2810(void *),FUN_0888b898(void *),FUN_08886988(void *),FUN_08a9e0cc(void *);
void FUN_0888732c(void **p) { *p=&DAT_08bb0c78; FUN_08ad3088(&DAT_08bef8f4); FUN_088855c4(&DAT_08bedbe0,0,0); FUN_08ad2810(&DAT_08bef8f4); FUN_0888b898(p+12); FUN_08886988(p); DAT_08bedc38=0; }


// Two instructions exchanged in prologue; O2 gives same result.

// Two prologue instructions exchanged, same as related 0x08886a5c.
// near miss from lane lbp13b (unreviewed)
