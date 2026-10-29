/* LBPMATCH module=EBOOT.BIN start=0x08884708 end=0x08884750 symbol=FUN_08884708 lang=c99 */
/* Clone of src/eboot/f088844d4_088844d4.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb0b70, DAT_08bedc2c;
extern void FUN_0888f6b0(void *), FUN_08884634(void *), FUN_08a9e0cc(void *);
void FUN_08884708(void **p) { *p = &DAT_08bb0b70; FUN_0888f6b0((char *)p+44); FUN_08884634(p); DAT_08bedc2c = 0; FUN_08a9e0cc(p); }
