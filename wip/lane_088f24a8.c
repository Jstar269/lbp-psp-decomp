/* LBPMATCH module=EBOOT.BIN start=0x088f24a8 end=0x088f2774 symbol=FUN_088f24a8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct O { void (**vt)(struct O *); int refs; char pad[52]; unsigned short flags; char pad2[2]; void *callback,*data; } O;
extern unsigned DAT_08beedd8; extern char DAT_08beedc4,DAT_08bef8f4; extern void *DAT_08bdbdd8[];
extern char *FUN_08a6dc08(void *); extern void FUN_0883b1bc(O **), FUN_08a9c164(void *,char *),FUN_08a9c7dc(void *,void *,void *),FUN_089211a8(O *,void *),FUN_089377f0(O **),FUN_08ad3088(void *),FUN_08ad2810(void *),FUN_08a9bff8(void *),FUN_088f32cc(void);
extern int FUN_089ea5c8(int); extern long long FUN_08a9b8a4(void *,void *),FUN_088eb2dc(void *,O **); extern void *FUN_08a9e824(int);
static void release(O *p) { int n; if(p) { FUN_08ad3088(&DAT_08bef8f4); n=--p->refs; FUN_08ad2810(&DAT_08bef8f4); if(!n) p->vt[2](p); } }
int FUN_088f24a8(void *unused,char *input,unsigned *count,int *done) {
 char *s; O *p,*q; char text[32]; void *a[2],*b[2],*copy; long long result;
 if(DAT_08beedd8>=20) return 0; if(++*count>=10) return 0; s=FUN_08a6dc08(input); if(!s||!*s) return 1;
 FUN_0883b1bc(&p); if(p) { FUN_08a9c164(text,s); a[0]=DAT_08bdbdd8[FUN_089ea5c8(23)]; a[1]=(void *)(int)FUN_08a9b8a4(a,a[0]); b[0]=DAT_08bdbdd8[FUN_089ea5c8(2)]; b[1]=(void *)(int)FUN_08a9b8a4(b,b[0]); FUN_08a9c7dc(text,a,b); copy=FUN_08a9e824(20); __builtin_memcpy(copy,input,20); FUN_089211a8(p,text); p->data=copy; p->callback=FUN_088f32cc; p->flags &= ~0x600; FUN_089377f0(&p); q=p; if(q) { FUN_08ad3088(&DAT_08bef8f4); ++q->refs; FUN_08ad2810(&DAT_08bef8f4); } result=FUN_088eb2dc(&DAT_08beedc4,&q); release(q); ++*done; FUN_08a9bff8(text); }
 release(p); return 1;
}

// 179 words differ; object layout, string temporaries, and lifetime handling need review.
// near miss from lane lbp15d (unreviewed)
