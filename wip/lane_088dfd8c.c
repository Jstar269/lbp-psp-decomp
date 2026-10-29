/* LBPMATCH module=EBOOT.BIN start=0x088dfd8c end=0x088e0088 symbol=FUN_088dfd8c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct Node { struct Node *next,*prev; char data[20]; } Node;
extern void *DAT_08be84a0;
extern void FUN_08adbc24(void *,void *,int), FUN_08a9e0c4(void *), FUN_08b9e7a8(void *,void *,unsigned), FUN_08b88fac(void *,void *), FUN_08b9eb88(void *,int,int);
extern void *FUN_08adbb84(void *,int), *FUN_08a9e824(unsigned);
void FUN_088dfd8c(Node *self, unsigned *input) {
 Node *p,*n,*lists[3]; unsigned i,*pairs=input+4; char *names=(char *)(pairs+input[1]*2); unsigned *last=(unsigned *)(names+input[2]*16); char *buf,*data;
 lists[0]=self; lists[1]=(Node *)((char *)self+8); lists[2]=(Node *)((char *)self+16);
 for(i=0;i<3;i++) { Node *head=lists[i]; p=head->next; while(p!=head) { n=p->next; FUN_08adbc24(DAT_08be84a0,p,i==1?28:16); p=n; } head->next=head; head->prev=head; }
 *(unsigned *)((char *)self+32)|=2;
 buf=*(char **)((char *)self+24); if(buf) FUN_08a9e0c4(buf);
 if(*input) { buf=FUN_08a9e824(*input&~1u); *(char **)((char *)self+24)=buf; FUN_08b9e7a8(buf,last+input[3]*2,*input); data=buf;
 for(i=0;i<input[1];i++) { unsigned a=pairs[0],b=pairs[1]; p=FUN_08adbb84(DAT_08be84a0,16); if(p->data) { *(char **)(p->data)=data+a*2+2; *(char **)(p->data+4)=data; } FUN_08b88fac(p,lists[0]); data+=(a+b)*2+4; pairs+=2; }
 } else *(void **)((char *)self+24)=0;
 for(i=0;i<input[2];i++) { char tmp[20],*d=tmp,*s=names; FUN_08b9eb88(tmp,0,20); while(*s) *d++=*s++; p=FUN_08adbb84(DAT_08be84a0,28); if(p->data) __builtin_memcpy(p->data,tmp,20); FUN_08b88fac(p,lists[1]); names+=16; }
 for(i=0;i<input[3];i++) { unsigned a=last[0],b=last[1]; p=FUN_08adbb84(DAT_08be84a0,16); if(p->data) { *(unsigned *)p->data=a; *(unsigned *)(p->data+4)=b; } FUN_08b88fac(p,lists[2]); last+=2; }
}
// 189 words differ; list reset loop changes layout; reconstruction needs type and scheduling refinement.
// near miss from lane lbp15d (unreviewed)
