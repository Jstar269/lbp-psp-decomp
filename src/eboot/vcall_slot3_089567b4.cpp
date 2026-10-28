/* LBPMATCH module=EBOOT.BIN start=0x089567b4 end=0x089567e8 symbol=FUN_089567b4 lang=c++ */
/* Clone of src/eboot/vcall_slot3_0894c3f8.cpp (lbpclone.py tag c14): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_089567b4(Owner *owner, int *out)
{
    owner->target->m3();
    *out = 0;
}
