/* LBPMATCH module=EBOOT.BIN start=0x08b97e14 end=0x08b97fa8 symbol=FUN_08b97e14 lang=c99 rodata=0x08bda1b0 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_08b9ca68(void); extern char *FUN_08b97d88(char *,unsigned *),*FUN_08b97dbc(char *,unsigned *);
char *FUN_08b97e14(unsigned char enc, char *base, char *p, unsigned *out) { unsigned v; char *orig=p;
 if(enc==0x50) { p=(char *)(((unsigned)p+3)&~3); v=*(unsigned *)p; p+=4; } else { switch(enc&15) { case 0: case 3: case 11: __builtin_memcpy(&v,p,4); p+=4; break; case 4: case 12: __builtin_memcpy(&v,p,4); p+=8; break; case 1: p=FUN_08b97d88(p,&v); break; case 9: p=FUN_08b97dbc(p,&v); break; case 2: v=(unsigned char)p[0]|((unsigned char)p[1]<<8); p+=2; break; case 10: v=(short)((unsigned char)p[0]|((unsigned char)p[1]<<8)); p+=2; break; default: FUN_08b9ca68(); v=0; }
 if(v) { if((enc&0x70)==0x10) base=orig; v+=(unsigned)base; if((signed char)enc<0) v=*(unsigned *)v; } } *out=v; return p; }
// 90 words differ; target range also contains adjacent code starting at 0x08b97f74.
// near miss from lane lbp13d (unreviewed)
