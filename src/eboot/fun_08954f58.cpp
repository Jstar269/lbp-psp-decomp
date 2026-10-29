/* LBPMATCH module=EBOOT.BIN start=0x08954f58 end=0x08954f80 symbol=FUN_08954f58 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" int DAT_08befa14;
extern "C" void FUN_08954f80();
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(void (*)(), int, int, int); };
extern "C" void FUN_08954f58(Obj *p) { DAT_08befa14 = 0; p->f7(FUN_08954f80, 0, 0, 1); }
