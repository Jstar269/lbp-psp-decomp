/* LBPMATCH module=EBOOT.BIN start=0x088a18b4 end=0x088a18dc symbol=FUN_088a18b4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); names and types await human review. */
extern char DAT_08bb2678; extern void FUN_088a1954(void); extern void FUN_08b2d79c(void *,void *,void *,void *);
void FUN_088a18b4(char *p) { p-=12; FUN_08b2d79c(p+8,&DAT_08bb2678,FUN_088a1954,p); }
// 10 words differ: adjusting thunk branches into shared registration body; direct C collapses it.
// near miss from lane lbp14c (unreviewed)
