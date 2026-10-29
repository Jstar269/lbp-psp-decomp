/* LBPMATCH module=EBOOT.BIN start=0x088844d4 end=0x0888451c symbol=FUN_088844d4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb0ba0, DAT_08bedfa8;
extern void FUN_0888b898(void *), FUN_088843c0(void *), FUN_08a9e0cc(void *);
void FUN_088844d4(void **p) { *p = &DAT_08bb0ba0; FUN_0888b898((char *)p+44); FUN_088843c0(p); DAT_08bedfa8 = 0; FUN_08a9e0cc(p); }
