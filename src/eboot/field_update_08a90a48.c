/* LBPMATCH module=EBOOT.BIN start=0x08a90a48 end=0x08a90ac4 symbol=FUN_08a90a48 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/field_update_08a76a44.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Obj Obj; typedef struct Child Child;
struct Child { void *(**vt)(Child *); }; struct Obj { void (**vt)(Obj *); char pad[396]; Child *child; };
void FUN_08a90a48(Obj *p, float f) { if (p->child) { float *v=p->child->vt[9](p->child); v[3]=f; p->vt[67](p); p->vt[68](p); } }


