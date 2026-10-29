/* LBPMATCH module=EBOOT.BIN start=0x08947b34 end=0x08947d44 symbol=FUN_08947b34 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_08b9eb88(void *,int,int),FUN_08baa4fc(void *,void *),FUN_08ba0868(void *,int,void *); extern int FUN_0894a2f0(void *),FUN_0894a2e8(void *); extern void *DAT_08bef8d8; extern char DAT_08bef8d4;
void FUN_08947b34(char *p,char **arg) { char *src,*obj; int i,v; FUN_08b9eb88(p+4,0,1536); *(int *)(p+4)=1536; FUN_08baa4fc(p+8,p+12); *(int *)(p+28)=31; *(int *)(p+16)=32; *(int *)(p+24)=33; *(int *)(p+20)=34; src=*arg; __builtin_memcpy(p+1504,src+1384,16); FUN_08ba0868(p+64,13,DAT_08bef8d8); FUN_08ba0868(p+80,20,*arg+24); FUN_08ba0868(p+104,13,*arg+1344);
 for(i=0;i<3;i++) { src=*arg; obj=*(char **)(src+48+4*i); if(obj) { obj=*(char **)(obj+168); *(int *)(p+1416+16*i)=FUN_0894a2f0(obj); v=FUN_0894a2e8(obj); *(int *)(p+1420+16*i)=v; *(int *)(p+1424+16*i)=v; } }
 FUN_08ba0868(p+132,128,*arg+60); FUN_08ba0868(p+260,128,*arg+188); FUN_08ba0868(p+388,1024,*arg+316); p[1412]=DAT_08bef8d4; src=*arg; *(int *)(p+52)=13; *(int *)(p+60)=(unsigned char)src[44]; *(int *)(p+120)=*(int *)(src+1360); *(int *)(p+124)=*(int *)(src+1368); *(int *)(p+128)=*(int *)(src+1376); *(int *)(p+1524)=*(int *)(src+20); }
// 125 words differ; repeated conditional blocks were looped and need inline reconstruction.
// near miss from lane lbp13d (unreviewed)
