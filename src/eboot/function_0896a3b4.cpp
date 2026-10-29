/* LBPMATCH module=EBOOT.BIN start=0x0896a3b4 end=0x0896a41c symbol=FUN_0896a3b4 lang=c++ */
/* Clone of src/eboot/function_0896a34c.cpp (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" char DAT_08bb88b0; extern "C" void FUN_0896b250(void *);
struct V { virtual void unused(); virtual void release(); };
extern "C" void FUN_0896a3b4(void **p) { p[0]=&DAT_08bb88b0; if(p[6]) ((V *)p[6])->release(); if(p[7]) ((V *)p[7])->release(); FUN_0896b250(p); }
