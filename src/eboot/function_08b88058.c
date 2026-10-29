/* LBPMATCH module=EBOOT.BIN start=0x08b88058 end=0x08b8808c symbol=FUN_08b88058 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bd8f28,DAT_08bd8e64; extern void FUN_08b8e164(void); extern void *FUN_08b8ccc0(int); extern void FUN_08b8dc60(void *,void *,void *) __attribute__((noreturn));
void FUN_08b88058(void) { void **p=FUN_08b8ccc0(4); *p=&DAT_08bd8f28; FUN_08b8dc60(p,&DAT_08bd8e64,FUN_08b8e164); }
