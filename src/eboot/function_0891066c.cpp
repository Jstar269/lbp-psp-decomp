/* LBPMATCH module=EBOOT.BIN start=0x0891066c end=0x089106d4 symbol=FUN_0891066c lang=c++ */
/* Clone of src/eboot/function_08910604.cpp (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14a, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" char DAT_08bb60e8;
struct V { virtual void unused(); virtual void release(); };
extern "C" void FUN_0891066c(void **p) { p[0]=&DAT_08bb60e8; for(int i=0;i<20;i++) { V *v=(V *)p[i+3]; if(v) { v->release(); p[i+3]=0; } } }
