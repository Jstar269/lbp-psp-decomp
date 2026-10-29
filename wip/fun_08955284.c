/* LBPMATCH module=EBOOT.BIN start=0x08955284 end=0x089552c8 symbol=FUN_08955284 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
typedef struct { char pad[4]; char *cur; char pad2[12]; int size; char pad3[24]; unsigned char *state; } Stream;
void FUN_08955284(Stream *s,unsigned char x) { int v=x; if(!s->state[12]) __builtin_memcpy(s->cur,&v,4); s->cur+=4; s->size+=4; }
// 15 words differ in 18/17-word result; store scheduling and branch-likely differ; O2 worse.
// near miss from lane lbp13d (unreviewed)
