/* LBPMATCH module=EBOOT.BIN start=0x08a9fe88 end=0x08a9fef0 symbol=FUN_08a9fe88 lang=c99 */
/* Clone of src/eboot/function_08a9fe20.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bcad20,DAT_08bf9300; extern void FUN_08a9fd24(void *,void *), FUN_08a9e0cc(void *),FUN_08a9bff8(void *);
void FUN_08a9fe88(char *p) { void *x=*(void **)(p+168); *(void **)p=&DAT_08bcad20; FUN_08a9fd24(&DAT_08bf9300,&x); if(*(void **)(p+172)) FUN_08a9e0cc(*(void **)(p+172)); FUN_08a9bff8(p+144); FUN_08a9bff8(p+120); }
