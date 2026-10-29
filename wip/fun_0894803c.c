/* LBPMATCH module=EBOOT.BIN start=0x0894803c end=0x08948160 symbol=FUN_0894803c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void *DAT_08bef8d8;
extern void FUN_08b9eb88(void *,int,int), FUN_08baa4fc(void *,void *), FUN_08ba0868(void *,int,void *);
void FUN_0894803c(char *self, char **p) {
 char *s; int x,y,z,w; unsigned char v;
 FUN_08b9eb88(self+4,0,1536); *(int *)(self+4)=1536; FUN_08baa4fc(self+8,self+12);
 *(int *)(self+28)=31; *(int *)(self+16)=32; *(int *)(self+24)=33; *(int *)(self+20)=34;
 __builtin_memcpy(self+1504,*p+88,16);
 FUN_08ba0868(self+64,13,DAT_08bef8d8); FUN_08ba0868(self+80,20,*p+24); FUN_08ba0868(self+104,13,*p+48);
 s=*p; *(int *)(self+52)=15; x=*(int *)(s+64); y=*(int *)(s+72); z=*(int *)(s+80); w=*(int *)(s+20);
 *(int *)(self+120)=x; *(int *)(self+124)=y; *(int *)(self+128)=z; *(int *)(self+1524)=w;
}



// Struct typing and instruction scheduling remain unresolved.
// near miss from lane lbp13c (unreviewed)
