/* LBPMATCH module=EBOOT.BIN start=0x088ce2a8 end=0x088ce44c symbol=FUN_088ce2a8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g11) corrected by hand (lane lbp13d, Codex GPT-6): unaligned copies; names and types await human review. */
extern void FUN_088ce110(void *);
typedef struct Node { struct Node *next; int pad; char data[20]; } Node;
void FUN_088ce2a8(char *self, const char *src, char *ctx) {
 Node *p; unsigned char n;
 __builtin_memcpy(self,src,20); self[60]=0; self[61]=0; *(int *)(self+64)=0; FUN_088ce110(self);
 *(int *)(self+64)|=1; *(int *)(self+68)=*(int *)(ctx+40); *(int *)(self+72)=*(int *)(ctx+48); *(int *)(self+76)=*(int *)(ctx+56);
 *(short *)(self+58)=*(short *)(ctx+72); *(short *)(self+56)=(short)*(int *)(ctx+68); *(short *)(self+54)=(short)*(int *)(ctx+64);
 for(p=*(Node **)(ctx+20);p!=(Node *)(ctx+20);p=p->next) { n=self[60]++; *(int *)(self+80+4*n)=*(int *)(p->data+4); }
 for(p=*(Node **)(ctx+28);p!=(Node *)(ctx+28);p=p->next) { n=self[61]++; __builtin_memcpy(self+1080+16*n,p->data,16); }
}
// 105 words differ; 98 versus 105 words. Packed-copy and loop scheduling remain different.
// near miss from lane lbp13d (unreviewed)
