/* LBPMATCH module=EBOOT.BIN start=0x088c6818 end=0x088c68f8 symbol=FUN_088c6818 lang=c++ */
/* Clone of src/eboot/build_handle_088c6630.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Mutex { int a; };
extern Mutex DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_088c6000();
extern "C" void FUN_088c601c();
struct Big {
    void **vt;
    int count;
    char pad[576];
    int f584;
    char pad2[132];
    void (*f720)();
    void (*f724)();
    void *f728;
    void *f732;
};
struct Handle {
    Big *p;
    ~Handle()
    {
        Big *r = p;
        if (r) {
            FUN_08ad3088(&DAT_08bef8f4);
            int c = r->count - 1;
            r->count = c;
            FUN_08ad2810(&DAT_08bef8f4);
            if (c == 0) ((void (*)(Big *))r->vt[2])(r);
        }
    }
};
struct Owner {
    char pad[140];
    unsigned flags;
};
extern "C" void FUN_0883a3c8(Handle *h);
extern "C" void FUN_08921bec(Handle *h);
extern "C" void FUN_08922ce0(Handle *h, int size, int a, int b);
extern "C" void FUN_08922a00(Handle *h, int a);
extern "C" void FUN_088c6818(Owner *self)
{
    self->flags = 0;
    Handle h;
    FUN_0883a3c8(&h);
    FUN_08921bec(&h);
    FUN_08922ce0(&h, 572, 0, 0);
    Big *b = h.p;
    b->f584 = 400;
    self->flags &= ~0xfeu;
    b->f720 = FUN_088c6000;
    b->f724 = FUN_088c601c;
    b->f728 = self;
    b->f732 = self;
    FUN_08922a00(&h, 0);
}
