/* LBPMATCH module=EBOOT.BIN start=0x0882ec70 end=0x0882ee28 symbol=FUN_0882ec70 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp2a, Codex GPT-6); exact match verified; names and types await human review. */
struct Node { int a,b; Node *next,*child; };
extern "C" unsigned int DAT_08be84a0;
extern "C" void FUN_08adbc24(unsigned int, Node *, int);
extern "C" void FUN_0882ec70(void *self, Node *p) {
 while (p) { FUN_0882ec70(self,p->child); Node *next=p->next; FUN_08adbc24(DAT_08be84a0,p,0x20); p=next; }
}

