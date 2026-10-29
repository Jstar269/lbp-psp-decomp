/* LBPMATCH module=EBOOT.BIN start=0x08a5740c end=0x08a5742c symbol=FUN_08a5740c lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern "C" float DAT_08bb08e8;
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39(); virtual void f40(); virtual void f41(float); };
extern "C" void FUN_08a5740c(Obj *p, int n) { p->f41(n * DAT_08bb08e8); }

// Seven words differ: float scheduling and registers; Os and O2 tried.
// near miss from lane lbp15b (unreviewed)
