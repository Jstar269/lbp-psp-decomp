/* LBPMATCH module=EBOOT.BIN start=0x089e0bec end=0x089e0c28 symbol=FUN_089e0bec lang=c99 */
/* Clone of src/eboot/f0897378c_0897378c.c (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py tag g13) corrected by hand (lane lbp15a, Codex GPT-6): simplified types and mask; exact match verified; names and types await human review. */
typedef struct Obj Obj;
struct Obj { void (**vtable)(Obj *); unsigned flags; };
void FUN_089e0bec(char *self) {
    Obj *p = *(Obj **)(self + 24);
    p->vtable[10](p);
    p->flags &= ~0x200;
}
