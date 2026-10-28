/* LBPMATCH module=EBOOT.BIN start=0x089ee1b4 end=0x089ee3b4 symbol=FUN_089ee1b4 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
struct Node { int a,b; Node *next,*child; }; extern void *DAT_08be84a0; extern "C" void FUN_08adbc24(void *,void *,int);
extern "C" inline __attribute__((used)) void FUN_089ee1b4(void *self,Node *n) { while(n) { FUN_089ee1b4(self,n->child); Node *next=n->next; FUN_08adbc24(DAT_08be84a0,n,24); n=next; } }
// Recursive inline form emits fewer levels than retail; 123 differing words.
// near miss from lane lbp1a (unreviewed)
