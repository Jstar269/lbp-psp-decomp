/* LBPMATCH module=EBOOT.BIN start=0x08aa3ecc end=0x08aa4044 symbol=_ZN7Surface4blitEjjjjPS_jj lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Format { char pad[16]; int id; };
struct Surface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Format *format();
    virtual Format *dstFormat();
    char pad[32 - 4];
    unsigned short *data;
    char pad2[4]; // placeholder
    unsigned stride;
    void blit(unsigned sx, unsigned sy, unsigned w, unsigned h, Surface *dst, unsigned dx, unsigned dy);
};
extern "C" void FUN_08aa3c68(Surface *self, unsigned sx, unsigned sy, unsigned w, unsigned h, Surface *dst, unsigned dx, unsigned dy);
void Surface::blit(unsigned sx, unsigned sy, unsigned w, unsigned h, Surface *dst, unsigned dx, unsigned dy)
{
    if (dst->dstFormat()->id != format()->id) {
        FUN_08aa3c68(this, sx, sy, w, h, dst, dx, dy);
        return;
    }
    for (unsigned y = 0; y < h; y++) {
        unsigned soff = sx * 2, doff = dx * 2;
        for (unsigned x = 0; x < w; x++) {
            *(unsigned short *)((char *)dst->data + dst->stride * (y + dy) * 2 + doff) =
                *(unsigned short *)((char *)data + stride * (y + sy) * 2 + soff);
            soff += 2;
            doff += 2;
        }
    }
}
// NEAR (~70 words): body codegen close (byte-offset induction variables as in retail, mult per iteration); retail lays the format-mismatch fallback (arg moves + tail call 0x08aa3c68) out of line after the loops and enters the outer loop with beq to its test; ours keeps the fallback inline and allocates registers differently. Index-form inner loop and gcc404xs-O2 were worse.
// near miss from lane lbp8a (unreviewed)
