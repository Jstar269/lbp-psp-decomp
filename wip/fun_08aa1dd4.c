/* LBPMATCH module=EBOOT.BIN start=0x08aa1dd4 end=0x08aa1fec symbol=FUN_08aa1dd4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_08b9eb88(void *,int,int);
void FUN_08aa1dd4(short *s,const char *input) { short vals[4],v[4]; int row,col,k; unsigned flags=(unsigned short)s[2]; int pos=s[1]; char *p,*q; __builtin_memcpy(vals,input,8);
 for(row=0;row<2;row++) { p=*(char **)((char *)s+12+row*4)+pos*8+16; for(col=0;col<3;col++) { int factor=*(int *)((char *)s+24+4*(row*3+((flags&1)?2-col:col))); __builtin_memcpy(v,p,8); for(k=0;k<4;k++) v[k]+=vals[k]*factor; __builtin_memcpy(p,v,8); p+=8; } }
 if((flags&1)?pos>0:pos<s[0]-1) { s[1]+= (flags&1)?-1:1; return; } p=*(char **)((char *)s+12); q=*(char **)((char *)s+16); *(char **)((char *)s+16)=p; *(char **)((char *)s+12)=q; FUN_08b9eb88(p,0,s[10]*8); s[2]++;
}
// 130 words differ; inner vector arithmetic and stack temporaries differ.
// near miss from lane lbp13d (unreviewed)
