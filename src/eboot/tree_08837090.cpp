/* LBPMATCH module=EBOOT.BIN start=0x08837090 end=0x08837248 symbol=FUN_08837090 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp2a, Codex GPT-6); exact match verified; names and types await human review. */
struct Node { int a,b; Node *next,*child; };
extern "C" unsigned int DAT_08be84a0;
extern "C" void FUN_08adbc24(unsigned int, Node *, int);
extern "C" void FUN_08837090(void *self, Node *p) {
 while (p) { FUN_08837090(self,p->child); Node *next=p->next; FUN_08adbc24(DAT_08be84a0,p,0x30); p=next; }
}

