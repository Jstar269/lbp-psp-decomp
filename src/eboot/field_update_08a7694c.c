/* LBPMATCH module=EBOOT.BIN start=0x08a7694c end=0x08a769c8 symbol=FUN_08a7694c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Obj Obj; typedef struct Child Child;
struct Child { void *(**vt)(Child *); }; struct Obj { void (**vt)(Obj *); char pad[396]; Child *child; };
void FUN_08a7694c(Obj *p, float f) { if (p->child) { float *v=p->child->vt[9](p->child); v[1]=f; p->vt[67](p); p->vt[68](p); } }


