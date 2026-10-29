/* LBPMATCH module=EBOOT.BIN start=0x088fd078 end=0x088fd11c symbol=FUN_088fd078 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. A destructor body: derived vtable pointer, member destructors (an inlined holder with a one-element array of intrusive reference-counted pointers), base vtable pointer, base destructor as a tail call. */
extern "C" char DAT_08bb59a0[];
extern "C" char DAT_08bb4f48[];
extern "C" void FUN_0891077c(void *self);
struct Counted {
    void **vptr;
    int rc;
    void Release() {
        if (--rc == 0)
            ((void (*)(Counted *))vptr[2])(this);
    }
};
struct Ref {
    Counted *p;
    ~Ref() { if (p) p->Release(); }
};
struct Holder { Ref refs[1]; };
struct Obj {
    void *vptr;
    char base[24];
    Holder held;
};
extern "C" void FUN_088fd078(Obj *self)
{
    self->vptr = DAT_08bb59a0;
    self->held.~Holder();
    self->vptr = DAT_08bb4f48;
    FUN_0891077c(self);
}
// NEAR: 29 words differ, same instructions but retail enters the one-element member-array destroy loop via "li s2,2; move s0,v1; bnez v1,L; (sw vptr); j exit" in the first block while ours emits "beqz v1,exit" then a block ending in j into the loop; O2 unrolls the loop (worse); gcc402x/410/171 no better. Holder-with-array-member dtor inlined into a free function reproduces the loop itself (real dtor gives the same layout as ours).
// near miss from lane lbp8a (unreviewed)
