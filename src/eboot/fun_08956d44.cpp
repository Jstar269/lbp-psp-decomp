/* LBPMATCH module=EBOOT.BIN start=0x08956d44 end=0x08956d6c symbol=FUN_08956d44 lang=c++ */
/* Clone of src/eboot/fun_08954f58.cpp (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" int DAT_08befa50;
extern "C" void FUN_08956d6c();
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(void (*)(), int, int, int); };
extern "C" void FUN_08956d44(Obj *p) { DAT_08befa50 = 0; p->f7(FUN_08956d6c, 0, 0, 1); }
