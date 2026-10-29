/* LBPMATCH module=EBOOT.BIN start=0x08947f10 end=0x0894803c symbol=FUN_08947f10 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void *DAT_08bef8d8;
extern void FUN_08b9eb88(void *,int,int), FUN_08baa4fc(void *,void *), FUN_08ba0868(void *,int,void *);
void FUN_08947f10(char *self, char **p) {
 char *s; int x,y,z,w; unsigned char v;
 FUN_08b9eb88(self+4,0,1536); *(int *)(self+4)=1536; FUN_08baa4fc(self+8,self+12);
 *(int *)(self+28)=31; *(int *)(self+16)=32; *(int *)(self+24)=33; *(int *)(self+20)=34;
 __builtin_memcpy(self+1504,*p+88,16);
 FUN_08ba0868(self+64,13,DAT_08bef8d8); FUN_08ba0868(self+80,20,*p+24); FUN_08ba0868(self+104,13,*p+48);
 s=*p; *(int *)(self+52)=17; v=(unsigned char)s[44]; x=*(int *)(s+64); y=*(int *)(s+72); z=*(int *)(s+80); w=*(int *)(s+20);
 *(int *)(self+120)=x; *(int *)(self+124)=y; *(int *)(self+128)=z; *(int *)(self+1524)=w; *(int *)(self+60)=v;
}


// 12 words differ in scheduling and alias analysis.
// near miss from lane lbp13c (unreviewed)
