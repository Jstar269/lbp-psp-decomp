/* LBPMATCH module=EBOOT.BIN start=0x0894c3f8 end=0x0894c42c symbol=FUN_0894c3f8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbpt0, Claude Opus 5.5, lane-tool test); exact match verified; names and types await human review. Calls the fourth virtual function of the object at +0xa8 and clears the result word. */
class Target {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Owner {
    char pad[0xa8];
    Target *target;
};

extern "C" void FUN_0894c3f8(Owner *owner, int *out)
{
    owner->target->m3();
    *out = 0;
}
