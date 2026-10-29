/* LBPMATCH module=EBOOT.BIN start=0x088e4624 end=0x088e48fc symbol=FUN_088e4624 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct N { struct N *next,*prev; void *value; } N;
extern void *DAT_08beed14,*DAT_08be84a0,*DAT_08beee0c,*DAT_08bf03b8;
extern void *FUN_088dc4b4(void *),*FUN_08adbb84(void *,int),*FUN_088827a8(unsigned *);
extern void FUN_08b88fac(void *,void *),FUN_08b88fc8(void *),FUN_08adbc24(void *,void *,int),FUN_088f3b0c(void *,void *),FUN_088e1c24(void *,int),FUN_088e447c(void **,int,void **),FUN_0896fbd4(void *,void **,int,int),FUN_08970b6c(void *);
void FUN_088e4624(char *self,N *incoming) {
 int *selected=(int *)self; int kind, special, count=0; N *head,*p; void *value,*msg,*item; unsigned i,end,cap=0; char *array;
 if(*(int *)((char *)FUN_088dc4b4(DAT_08beed14)+4)==2) selected=(int *)(self+28);
 kind=*selected; special=(kind==6||kind==15); head=(N *)(selected+5);
 while(incoming->next!=incoming) { p=incoming->next;
 if(special && !self[96]) { N *n=FUN_08adbb84(DAT_08be84a0,28); if(n->value) __builtin_memcpy(&n->value,p->value,20); FUN_08b88fac(n,self+100); }
 value=p->value; { N *n=FUN_08adbb84(DAT_08be84a0,12); if(n->value) n->value=value; FUN_08b88fac(n,head); }
 FUN_08b88fc8(p); FUN_08adbc24(DAT_08be84a0,p,12); }
 for(p=head->next;p!=head;p=p->next) count++; selected[4]=count;
 if(special && selected[3]-count && *(int *)(self+92)>=0) { array=FUN_088827a8(&cap); i=*(unsigned *)(self+92); end=i+selected[3]-count; if(end>cap) end=cap; *(unsigned *)(self+92)=end; for(;i<end;i++) FUN_088f3b0c(DAT_08beee0c,array+i*40+4); if(*(unsigned *)(self+92)>i) return; }
 FUN_088e1c24(selected,0); self[85]=1; i=*(unsigned short *)((char *)DAT_08beed14+596); item=0; if(i!=65535) { char *q=*(char **)((char *)DAT_08beed14+336)+i*40; if(q) item=*(void **)(q+4); } FUN_088e447c(&msg,32000,&item); FUN_0896fbd4(DAT_08bf03b8,&msg,1,((char *)selected)[4]?10:3); if(msg) FUN_08970b6c(msg);
}
// 176 words differ; list and bounds types need correction; return condition needs review.
// near miss from lane lbp15d (unreviewed)
