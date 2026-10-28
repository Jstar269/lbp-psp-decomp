/* LBPMATCH module=EBOOT.BIN start=0x089968d4 end=0x08996a8c symbol=FUN_089968d4 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp2a, Codex GPT-6); exact match verified; names and types await human review. */
struct Node { int a,b; Node *next,*child; };
extern "C" unsigned int DAT_08be84a0;
extern "C" void FUN_08adbc24(unsigned int, Node *, int);
extern "C" void FUN_089968d4(void *self, Node *p) {
 while (p) { FUN_089968d4(self,p->child); Node *next=p->next; FUN_08adbc24(DAT_08be84a0,p,0x14); p=next; }
}

