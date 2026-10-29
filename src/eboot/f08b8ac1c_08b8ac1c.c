/* LBPMATCH module=EBOOT.BIN start=0x08b8ac1c end=0x08b8ac80 symbol=FUN_08b8ac1c lang=c99 */
/* Clone of src/eboot/f08b8abb8_08b8abb8.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern int FUN_08ba0e8c(const char *);
extern void *FUN_08b8aa40(const char *,const char *,void *,const char *);
void FUN_08b8ac1c(void **out,const char *p,void *arg) { const char *end = (const char *)-1; if (p) end = p + FUN_08ba0e8c(p); *out = FUN_08b8aa40(p,end,arg,p); }
