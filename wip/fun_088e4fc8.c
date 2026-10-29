/* LBPMATCH module=EBOOT.BIN start=0x088e4fc8 end=0x088e5170 symbol=FUN_088e4fc8 lang=c99 rodata=0x08bb4870 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_088e40c0(void *,void *,int); extern int FUN_088e3e74(void *,int,int,int); extern void FUN_088f3748(void *,void *); extern void *DAT_08beee0c; extern char *DAT_08beed14; extern int DAT_08bb440c;
int FUN_088e4fc8(char *p) {
 int mode=*(int *)(p+56),kind; char *data; struct { int type, count, stride, unused; char *a,*b; } arg;
 if (!((unsigned)(mode-6)<3 || mode==15 || mode==16 || mode==18 || mode==20)) return 0;
 kind=*(int *)(p+28);
 if(kind==16) FUN_088e40c0(p,*(void **)(p+140),1);
 else if(kind==17) { data=*(char **)(p+140); if(FUN_088e3e74(p,14,1,DAT_08bb440c)) { *(char **)(p+140)=data; __builtin_memcpy(p+120,data,20); arg.stride=*(int *)(p+40); arg.count=(*(int *)(p+36)-1)*arg.stride+1; switch(*(int *)(p+28)) { case 10: arg.type=0; break; case 11: arg.type=9; break; case 12: arg.type=8; break; case 13: arg.type=7; arg.b=p+146; break; case 14: arg.type=4; arg.a=p+120; break; } FUN_088f3748(DAT_08beee0c,&arg); } } else return 0;
 DAT_08beed14[462]=1; return 1;
}
// 68 words differ; jump-table and temporary layout require refinement.
// near miss from lane lbp13d (unreviewed)
