/* LBPMATCH module=EBOOT.BIN start=0x088cdf64 end=0x088ce110 symbol=FUN_088cdf64 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void *DAT_08beee0c;
extern void FUN_088e666c(void *,int,void *);
typedef struct Node { struct Node *next; char pad[4]; char data[20]; } Node;
unsigned FUN_088cdf64(char *self, char *list, unsigned limit) {
 unsigned count=0; Node *end=(Node *)(list+28), *node;
 if (!limit) return 0;
 for (node=*(Node **)(list+28);node!=end;node=node->next) {
  char data[20]; unsigned char i; int j;
  __builtin_memcpy(data,node->data,20);
  for(i=0;i<(unsigned char)self[61];i++) {
   for(j=0;j<16;j++) if(data[j]!=self[1080+i*16+j]) break;
   if(j==16) break;
  }
  if(i==(unsigned char)self[61]) { struct { char data[20]; char flag; } out; __builtin_memcpy(out.data,node->data,20); out.flag=0; count++; FUN_088e666c(DAT_08beee0c,12,&out); if(count>=limit) return count; }
 }
 return count;
}
// 107 words differ; nested comparison and stack copies require closer reconstruction.
// near miss from lane lbp13d (unreviewed)
