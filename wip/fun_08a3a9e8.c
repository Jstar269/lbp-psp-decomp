/* LBPMATCH module=EBOOT.BIN start=0x08a3a9e8 end=0x08a3aa0c symbol=FUN_08a3a9e8 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern void *DAT_08bf6c5c; extern int DAT_08bc4978; extern void FUN_08a35074(void *);
void FUN_08a3a9e8(void **p) { if (DAT_08bf6c5c == p) DAT_08bf6c5c=0; *p=&DAT_08bc4978; FUN_08a35074(p); }

// Eight words differ: register allocation and store scheduling; Os and O2 tried.
// near miss from lane lbp15b (unreviewed)
