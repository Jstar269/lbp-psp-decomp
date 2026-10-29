/* LBPMATCH module=EBOOT.BIN start=0x08910604 end=0x0891066c symbol=FUN_08910604 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" char DAT_08bb60e8;
struct V { virtual void unused(); virtual void release(); };
extern "C" void FUN_08910604(void **p) { p[0]=&DAT_08bb60e8; for(int i=0;i<20;i++) { V *v=(V *)p[i+3]; if(v) { v->release(); p[i+3]=0; } } }
