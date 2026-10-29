/* LBPMATCH module=EBOOT.BIN start=0x089e09c4 end=0x089e09ec symbol=FUN_089e09c4 lang=c99 */
/* Clone of src/eboot/fun_089e099c.c (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bc1bb0;
struct Obj { void *vt; int a,b,c,d; char flag; };
void FUN_089e09c4(struct Obj *p) { p->flag=1; p->vt=&DAT_08bc1bb0; p->b=0; p->c=0; p->d=0; p->a=0; }


