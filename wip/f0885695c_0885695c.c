/* LBPMATCH module=EBOOT.BIN start=0x0885695c end=0x088569a4 symbol=FUN_0885695c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
extern int DAT_08baf0f0, DAT_08baec60;
extern void FUN_08856114(void *, void *);
extern void FUN_0885c9f8(void *);
void FUN_0885695c(void **p) {
    p[0] = &DAT_08baf0f0;
    FUN_08856114(p + 52, p[54]);
    p[0] = &DAT_08baec60;
    FUN_0885c9f8(p);
}
// Three scheduling differences around subobject call; Os and O2 tried.
// near miss from lane lbp14d (unreviewed)
