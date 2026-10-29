/* LBPMATCH module=EBOOT.BIN start=0x08b882d0 end=0x08b88304 symbol=FUN_08b882d0 lang=c99 */
/* Clone of src/eboot/function_08b88058.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bd8f10,DAT_08bd8e4c; extern void FUN_08b8e120(void); extern void *FUN_08b8ccc0(int); extern void FUN_08b8dc60(void *,void *,void *) __attribute__((noreturn));
void FUN_08b882d0(void) { void **p=FUN_08b8ccc0(4); *p=&DAT_08bd8f10; FUN_08b8dc60(p,&DAT_08bd8e4c,FUN_08b8e120); }
