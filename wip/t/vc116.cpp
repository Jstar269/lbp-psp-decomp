/* LBPMATCH module=EBOOT.BIN start=0x0894c42c end=0x0894c4a0 symbol=FUN_0894c42c lang=c++ cc=gcc404xs-Os */
struct Inner { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void Get(void *out); };
struct Outer {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void Get(void *out);
    int f4, f8, fc; bool f10; char pad[168 - 17]; Inner *f168;
};
extern "C" bool FUN_0894c42c(Outer *self, int a1, int *out, int a3, bool flag)
{
    if (flag) {
        self->f168->Get(out);
        self->f10 = true;
        *out = 0;
    } else
        self->Get(out);
    return true;
}
