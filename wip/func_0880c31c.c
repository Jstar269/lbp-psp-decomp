/* LBPMATCH module=EBOOT.BIN start=0x0880c31c end=0x0880c370 symbol=FUN_0880c31c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); names and types await human review. */
struct N { int p[2]; struct N *l,*r; short key; }; struct T { int x; struct N head; };
struct N *FUN_0880c31c(struct T *t,short *k){ struct N *h=&t->head,*n=*(struct N **)((char *)h+4),*best=h; while(n){ if(n->key >= *k) {best=n;n=n->l;} else n=n->r; } if(best!=h && *k>=best->key) h=best; return h; }
// Eight words differ in scheduling and register allocation; inverted branch improved from 19.
// near miss from lane lbp14c (unreviewed)
