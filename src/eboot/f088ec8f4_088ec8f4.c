/* LBPMATCH module=EBOOT.BIN start=0x088ec8f4 end=0x088ec958 symbol=FUN_088ec8f4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern void *FUN_08a9e838(unsigned int);
extern void FUN_088ec854(void *, int, void *);
void **FUN_088ec8f4(void **out, int arg, void *other) {
    void *p = FUN_08a9e838(28);
    FUN_088ec854(p, arg, other);
    *out = p;
    return out;
}
