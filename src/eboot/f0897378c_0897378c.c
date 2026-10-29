/* LBPMATCH module=EBOOT.BIN start=0x0897378c end=0x089737c8 symbol=FUN_0897378c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g13) corrected by hand (lane lbp15a, Codex GPT-6): simplified types and mask; exact match verified; names and types await human review. */
typedef struct Obj Obj;
struct Obj { void (**vtable)(Obj *); unsigned flags; };
void FUN_0897378c(char *self) {
    Obj *p = *(Obj **)(self + 24);
    p->vtable[10](p);
    p->flags &= ~0x200;
}
