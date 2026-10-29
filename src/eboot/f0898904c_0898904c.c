/* LBPMATCH module=EBOOT.BIN start=0x0898904c end=0x089890b0 symbol=FUN_0898904c lang=c99 */
/* Clone of src/eboot/f088ec8f4_088ec8f4.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern void *FUN_08a9e838(unsigned int);
extern void FUN_08988f6c(void *, int, void *);
void **FUN_0898904c(void **out, int arg, void *other) {
    void *p = FUN_08a9e838(28);
    FUN_08988f6c(p, arg, other);
    *out = p;
    return out;
}
