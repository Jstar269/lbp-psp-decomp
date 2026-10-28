/* LBPMATCH module=EBOOT.BIN start=0x0882e830 end=0x0882e9e8 symbol=FUN_0882e830 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp2a, Codex GPT-6); exact match verified; names and types await human review. */
struct Node { int a,b; Node *next,*child; };
extern "C" unsigned int DAT_08be84a0;
extern "C" void FUN_08adbc24(unsigned int, Node *, int);
extern "C" void FUN_0882e830(void *self, Node *p) {
 while (p) { FUN_0882e830(self,p->child); Node *next=p->next; FUN_08adbc24(DAT_08be84a0,p,0x1c); p=next; }
}


