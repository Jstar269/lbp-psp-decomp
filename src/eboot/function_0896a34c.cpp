/* LBPMATCH module=EBOOT.BIN start=0x0896a34c end=0x0896a3b4 symbol=FUN_0896a34c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" char DAT_08bb88b0; extern "C" void FUN_0896b250(void *);
struct V { virtual void unused(); virtual void release(); };
extern "C" void FUN_0896a34c(void **p) { p[0]=&DAT_08bb88b0; if(p[6]) ((V *)p[6])->release(); if(p[7]) ((V *)p[7])->release(); FUN_0896b250(p); }
