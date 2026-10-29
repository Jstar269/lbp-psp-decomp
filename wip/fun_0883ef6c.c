/* LBPMATCH module=EBOOT.BIN start=0x0883ef6c end=0x0883f170 symbol=FUN_0883ef6c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_08955c30(void *,void *),FUN_08957204(void *),FUN_08af767c(void *),FUN_08af72b0(void *,void *,int),FUN_08af7480(void *,void *),FUN_08a6dab8(void *,void *,int),FUN_0883e504(void *,int); extern int *FUN_0894b31c(void *); extern void *FUN_08a9e838(int);
int FUN_0883ef6c(int *self,int *arg,int flag,char opt) { int *node,*obj; int hash[5],hash2[5]; int state[24],state2[24];
 FUN_08955c30(arg,self+5); if(self[58] && !opt) { node=FUN_0894b31c((void *)self[40]); node[1]=0x4d4a424f; obj=FUN_08a9e838(32); FUN_08957204(obj); FUN_08af767c(state); FUN_08af72b0(state,(void *)self[6],self[8]); FUN_08af7480(state,hash); obj[7]=4; __builtin_memcpy((char *)obj+8,hash,20); FUN_08af767c(state2); FUN_08af72b0(state2,hash,20); FUN_08af7480(state2,hash2); (*(void (**)(void *,void *,void *))(*(char **)self[38]+44))((void *)self[38],node,&obj); FUN_08a6dab8((void *)self[56],hash2,1); if(obj && !--obj[1]) (*(void (**)(void *))(*(char **)obj+4))(obj); }
 self[27]=self[8]; if(self[8]) self[31]=self[6]; self[26]=(int)self; FUN_0883e504(self,7); if(flag) self[3]++; return 1; }
// 129 words differ; stack alignment, packed copy, reference lifetime need reconstruction.
// near miss from lane lbp13d (unreviewed)
