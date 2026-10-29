/* LBPMATCH module=EBOOT.BIN start=0x08b8cac8 end=0x08b8cb28 symbol=FUN_08b8cac8 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bd8cbc; extern void FUN_08b887b0(const char *) __attribute__((noreturn)); extern void *FUN_08b8c8a0(char *,char *,void *);
void FUN_08b8cac8(void **out,char **str,unsigned pos,unsigned len,void *arg) { char *p=*str; unsigned size=*(unsigned *)(p-12); if (pos>size) FUN_08b887b0(&DAT_08bd8cbc); size-=pos; if (len>size) len=size; *out=FUN_08b8c8a0(p+pos,p+pos+len,arg); }

// 18 words differ in branch placement, min operation, and argument registers; Os also tested.
// near miss from lane lbp14b (unreviewed)
