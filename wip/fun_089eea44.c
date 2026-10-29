/* LBPMATCH module=EBOOT.BIN start=0x089eea44 end=0x089eebc8 symbol=FUN_089eea44 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char *DAT_08bf374c; extern int FUN_08ba0e8c(char *), FUN_08954cc4(void *); extern void FUN_08954ca4(void *,int), FUN_08954e28(void *,int), FUN_0895541c(void *);
void FUN_089eea44(char **owner) {
 char *node=DAT_08bf374c;
 while(node) { int len=FUN_08ba0e8c(node+8), i; char *stream; int value;
  FUN_08954ca4(*owner,0x5354414d); FUN_08954e28(*owner,4); stream=*owner; value=*(int *)(*(char **)node+4);
  if (!FUN_08954cc4(*(void **)(stream+48))) __builtin_memcpy(*(char **)(stream+4),&value,4);
  *(char **)(stream+4)+=4; *(int *)(stream+20)+=4;
  for(i=0;i<80;i++) { char c=i<len?node[8+i]:0; stream=*owner;
   if(!FUN_08954cc4(*(void **)(stream+48))) **(char **)(stream+4)=c;
   ++*(char **)(stream+4); ++*(int *)(stream+20);
  }
  FUN_0895541c(owner); node=*(char **)(node+88);
 }
}
// Loop and stream writing control flow differ.
// near miss from lane lbp13c (unreviewed)
