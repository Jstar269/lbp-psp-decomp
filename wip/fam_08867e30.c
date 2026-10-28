/* LBPMATCH module=EBOOT.BIN start=0x08867e30 end=0x08867f40 symbol=FUN_08867e30 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef unsigned int u32;
extern char DAT_08bef8f4[];
extern char *DAT_08be84ac;
extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
extern void *FUN_08adbb84(void *,u32);
extern void FUN_08b899e4(int,void *,void *,void *);
typedef struct { u32 key; int *ref; } Value;
void *FUN_08867e30(char *tree,void *x,char *parent,Value *value) {
 int left=x || parent==tree+4 || value->key < *(u32 *)(parent+16);
 char *heap=DAT_08be84ac, *node; Value *v;
 FUN_08ad3088(heap+32); node=FUN_08adbb84(heap,24); FUN_08ad2810(heap+32);
 v=(Value *)(node+16);
 if(v) { v->key=value->key; v->ref=value->ref; if(v->ref) { FUN_08ad3088(DAT_08bef8f4); ++v->ref[1]; FUN_08ad2810(DAT_08bef8f4); } }
 FUN_08b899e4(left,node,parent,tree+4); ++*(int *)(tree+20); return node;
}
// Construction and refcount operations reconstructed; compare register allocation and instruction scheduling.
// near miss from lane lbp1a (unreviewed)
