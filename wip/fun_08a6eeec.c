/* LBPMATCH module=EBOOT.BIN start=0x08a6eeec end=0x08a6effc symbol=FUN_08a6eeec lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void FUN_08b9eb88(void *,int,int), FUN_08ba10e8(void *,const char *,int);
struct Array { char *data; int count; };
void FUN_08a6eeec(struct Array *a, const char *name, const char *value) {
 int i; char *p;
 for (i=0; i<a->count; i++) {
  p=a->data+i*100;
  if (!p[20]) { __builtin_memcpy(p,value,20); FUN_08b9eb88(a->data+i*100+20,0,80); FUN_08ba10e8(a->data+i*100+20,name,80); return; }
 }
}
// Loop and pointer allocation differ.
// near miss from lane lbp13c (unreviewed)
