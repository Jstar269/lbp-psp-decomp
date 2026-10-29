/* LBPMATCH module=EBOOT.BIN start=0x08849fc8 end=0x08849ff0 symbol=FUN_08849fc8 lang=c++ */
struct Obj { virtual void d0(); virtual void d1(); virtual void f(); };
struct Holder { Obj *o; };
extern "C" void FUN_08849fc8(Holder *h) { h->o->f(); }
// NEAR: retail makes a normal call (jalr, then lw ra / jr ra, frame 16, a0 = *param reloaded as the this pointer of slot 2) where ours emits the sibling call 'jr t9' without a frame; sibcall suppression not reproducible (same as lbp3b 0x08a34688/lbp3c 0x08878d74). Tried void and int returning virtual, local copy of the object pointer.
// near miss from lane lbp4c (unreviewed)
