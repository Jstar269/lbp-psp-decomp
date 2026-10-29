/* LBPMATCH module=EBOOT.BIN start=0x08a19be8 end=0x08a19d7c symbol=FUN_08a19be8 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp10c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Fmt { char pad[0x10]; int id; };
struct Px { char b[4]; };
struct Buf {
    char *data;
    int pad4;
    int stride;
    inline Px *at(int x, int y) { int ro = y * stride * 4; int xo = x * 4; return (Px *)(data + ro + xo); }
    inline Px get(int x, int y) { return *at(x, y); }
    inline void set(int x, int y, Px v) { *at(x, y) = v; }
};
struct Img {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13();
    virtual Fmt *getFmt();
    virtual Fmt *getFmt2();
    char pad[0x1c];
    Buf buf;
};
extern "C" void FUN_08aa3c68(Img *a, int x1, int y1, unsigned int w, unsigned int h, Img *b, int x2, int y2);
extern "C" void FUN_08a19be8(Img *a, int x1, int y1, unsigned int w, unsigned int h, Img *b, int x2, int y2)
{
    int idb = b->getFmt2()->id;
    if (idb == a->getFmt()->id) {
        for (unsigned int j = 0; j < h; j++) {
            for (unsigned int i = 0; i < w; i++) {
                Px v = a->buf.get(x1 + i, y1 + j);
                b->buf.set(x2 + i, y2 + j, v);
            }
        }
        return;
    }
    FUN_08aa3c68(a, x1, y1, w, h, b, x2, y2);
}
// NEAR ~24 words, all register naming/scheduling (loop counter t2 vs t6, temp regs, the three stack stores come before the dest address computation instead of after).
// Found: gcc404xs-O2 (Os gives the wrong layout); unsigned w/h (beqz/bne guards); `Buf` member struct at +0x20 (data, stride at +8) with inline at()/get()/set();
// `int ro = y*stride*4; int xo = x*4;` as separate statements keep (row*4) + IV(x*4) unfolded; a by-value Px (char[4], align 1) copied via get()/set() gives lwl/lwr, swl/swr and the three sp stores.
// near miss from lane lbp10c (unreviewed)
