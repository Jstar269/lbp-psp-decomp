/* LBPMATCH module=EBOOT.BIN start=0x08a4bda8 end=0x08a4bff4 symbol=FUN_08a4bda8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
extern void *FUN_08a9e4a4(unsigned,int,int);
extern void *FUN_08b9e7a8(void *, const void *, unsigned);
static unsigned read32(const char *p) { unsigned x; __builtin_memcpy(&x,p,4); return x; }
void FUN_08a4bda8(char *o, const char *p) {
 unsigned n,m,i; void *q;
 __builtin_memcpy(o+8,p,20); *(unsigned *)(o+28)=*(const unsigned *)(p+20);
 n=read32(p+24); *(unsigned *)(o+32)=n; q=FUN_08a9e4a4(n,0,0); *(void **)(o+36)=q; FUN_08b9e7a8(q,p+28,n);
 i=n+28; n=read32(p+i); m=read32(p+i+4); *(unsigned *)(o+40)=n; *(unsigned *)(o+44)=m; if(m) n=m; i+=8;
 q=FUN_08a9e4a4(n,0,0); *(void **)(o+48)=q; FUN_08b9e7a8(q,p+i,n); i+=n;
 n=read32(p+i); m=read32(p+i+4); *(unsigned *)(o+52)=n; *(unsigned *)(o+56)=m; if(m) n=m; __builtin_memcpy(o+64,p+i+8,20); i+=28;
 q=FUN_08a9e4a4(n,0,0); *(void **)(o+60)=q; FUN_08b9e7a8(q,p+i,n); i+=n;
 n=read32(p+i); *(unsigned *)(o+84)=n; i+=4; q=FUN_08a9e4a4(n,0,0); *(void **)(o+88)=q; FUN_08b9e7a8(q,p+i,n); i+=n;
 n=read32(p+i); *(unsigned *)(o+92)=n; q=FUN_08a9e4a4(n,0,0); *(void **)(o+96)=q; FUN_08b9e7a8(q,p+i+4,n);
}


// 135 words differ; primary profile emits the unaligned copies but has different register allocation and scheduling; O2 was 139 off.
// near miss from lane lbp15d (unreviewed)
