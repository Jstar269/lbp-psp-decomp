/* LBPMATCH module=EBOOT.BIN start=0x0887a024 end=0x0887a0fc symbol=FUN_0887a024 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern "C" int DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
struct Rc { int pad; int count; };
struct Handle {
    Rc *r;
    Handle() { r = 0; }
    Handle(const Handle &o) {
        Rc *rr = o.r;
        r = rr;
        if (rr) { FUN_08ad3088(&DAT_08bef8f4); rr->count++; FUN_08ad2810(&DAT_08bef8f4); }
    }
    ~Handle();
};
struct Node { char pad[16]; char key[28]; int state; Handle obj; };
struct Tree { int cmp; char header[16]; };
extern "C" char *FUN_088796e8(struct Tree *t, const void *key);
extern "C" void FUN_08879e80(void *mgr, const void *key);
struct Cache {
    char pad[12]; void *mgr; Tree tree;
    void touch(const void *key) { if (mgr) FUN_08879e80(mgr, key); }
};
extern "C" Handle FUN_0887a024(Cache *self, const void *key, bool strict)
{
    Node *n = (Node *)FUN_088796e8(&self->tree, key);
    if ((char *)n != self->tree.header && (!strict || n->state == 1)) {
        self->touch(key);
        return n->obj;
    }
    return Handle();
}
// NEAR 35 words: registers/frame match (n && (!strict||state==1) form); retail lays the 'if (mgr)' test block (bnez a0; j join, load of a0 in two delay slots) at the END of the function and the call block before the join; ours inlines it. Tried: inline member/free touch(), inline valid(), early returns, nested ifs, -O2.
// near miss from lane lbp11c (unreviewed)
