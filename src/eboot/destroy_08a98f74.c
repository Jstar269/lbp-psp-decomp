/* LBPMATCH module=EBOOT.BIN start=0x08a98f74 end=0x08a98fe4 symbol=FUN_08a98f74 lang=c99 */
/* Clone of src/eboot/destroy_08a98f04.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bca6b0;
extern void FUN_08a2ef7c(void *), FUN_08a9e0cc(void *), FUN_08adc5d8(void *), FUN_08adcd14(void *), FUN_08a6ae78(void *);
void FUN_08a98f74(void **p) {
 void *x=p[147]; p[0]=&DAT_08bca6b0;
 if(x) { FUN_08a2ef7c(x); FUN_08a9e0cc(x); FUN_08adc5d8(p[149]); }
 if(p[148]) FUN_08adcd14(p[148]);
 FUN_08a6ae78(p);
}
