/* LBPMATCH module=EBOOT.BIN start=0x0882580c end=0x0882586c symbol=FUN_0882580c lang=c99 */
/* Clone of src/eboot/f088256ac_088256ac.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bad844;
extern void *FUN_08a9e824(int);
extern int FUN_08ba0984(const char *,const char *,...);
void FUN_0882580c(void *unused, const char *text, void **out) { float *p=FUN_08a9e824(12); FUN_08ba0984(text,&DAT_08bad844,p,p+1,p+2); *out=p; }
