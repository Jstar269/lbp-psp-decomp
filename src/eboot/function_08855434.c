/* LBPMATCH module=EBOOT.BIN start=0x08855434 end=0x08855498 symbol=FUN_08855434 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08baf1a0,DAT_08baf178,DAT_08baf18c; extern void FUN_0894a258(void *), FUN_08b9eb88(void *,int,int);
void FUN_08855434(char *p) { FUN_0894a258(p); *(void **)p=&DAT_08baf1a0; *(int *)(p+4)=1; FUN_0894a258(p+8); *(void **)p=&DAT_08baf178; *(void **)(p+8)=&DAT_08baf18c; FUN_08b9eb88(p+12,0,20); }
