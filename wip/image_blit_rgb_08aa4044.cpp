/* LBPMATCH module=EBOOT.BIN start=0x08aa4044 end=0x08aa4208 symbol=FUN_08aa4044 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Format { char pad[16]; int id; };
struct Pixel { unsigned char r, g, b; };
struct Image {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual Format *format_dst();
    virtual Format *format_src();
    char pad[0x20 - 4];
    unsigned char *data;
    int f24;
    int pitch;
    unsigned char *row(int y) const { return data + 3 * pitch * y; }
    Pixel get(int x, int y) const { return *(const Pixel *)(row(y) + x * 3); }
    void set(int x, int y, Pixel p) { *(Pixel *)(row(y) + x * 3) = p; }
};
extern "C" void FUN_08aa3c68(Image *, int, int, unsigned, unsigned, Image *, int, int);
extern "C" void FUN_08aa4044(Image *src, int sx, int sy, unsigned w, unsigned h, Image *dst, int dx, int dy)
{
    if (dst->format_src()->id == src->format_dst()->id) {
        for (unsigned y = 0; y < h; y++)
            for (unsigned x = 0; x < w; x++)
                dst->set(dx + x, dy + y, src->get(sx + x, sy + y));
    } else {
        FUN_08aa3c68(src, sx, sy, w, h, dst, dx, dy);
    }
}
// NEAR ~20 words: structure, stack Pixel temporaries, prologue all match; remaining: order of the four loads at loop top (retail src pitch, src data, dst pitch, dst data) and the loop temp registers (t0..t4 numbering). row(y) helper = data + 3*pitch*y was needed for the retail register mapping; if/else (not early return) puts the fallback call after the loops as retail.
// near miss from lane lbp8b (unreviewed)
