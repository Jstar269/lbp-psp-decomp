/* LBPMATCH module=EBOOT.BIN start=0x089454dc end=0x08945540 symbol=FUN_089454dc lang=c99 */
/* Clone of src/eboot/function_08855434.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb7530,DAT_08bb7418,DAT_08bb742c; extern void FUN_0894a258(void *), FUN_08b9eb88(void *,int,int);
void FUN_089454dc(char *p) { FUN_0894a258(p); *(void **)p=&DAT_08bb7530; *(int *)(p+4)=1; FUN_0894a258(p+8); *(void **)p=&DAT_08bb7418; *(void **)(p+8)=&DAT_08bb742c; FUN_08b9eb88(p+12,0,20); }
