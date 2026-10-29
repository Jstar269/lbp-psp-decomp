/* LBPMATCH module=EBOOT.BIN start=0x08a958d4 end=0x08a95940 symbol=FUN_08a958d4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bca440; extern void *FUN_08a9e838(int), *FUN_08a0d5a4(void *); extern void FUN_08a0adf8(void *), FUN_08a0b5b0(void *,void *);
void **FUN_08a958d4(void **self) { void **p=FUN_08a9e838(192); FUN_08a0adf8(p); p[0]=&DAT_08bca440; p[32]=0; p[33]=0; FUN_08a0b5b0(p,self); p[46]=FUN_08a0d5a4(self[46]); return p; }
