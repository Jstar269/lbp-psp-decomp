/* LBPMATCH module=EBOOT.BIN start=0x08897a3c end=0x08897b58 symbol=FUN_08897a3c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void FUN_0888b8c4(void *), FUN_0888b8cc(void *), FUN_08ad3088(void *), FUN_08ad2810(void *);
extern void FUN_088975d0(void *, void *, void *, int, unsigned, unsigned);
extern char DAT_08bef8f4;
void **FUN_08897a3c(void **out, char *self, const char *src, void **p, unsigned char a, unsigned char b) {
 unsigned buf[5]; unsigned n, flags;
 FUN_0888b8c4(self+44);
 __builtin_memcpy(buf,src,20);
 n=*(unsigned *)(self+208); *(unsigned *)(self+208)=n+1;
 flags=a ? 2 : 1; if (b) flags |= 4;
 FUN_088975d0(self,buf,p,1,n,flags);
 FUN_0888b8cc(self+44);
 *out=*p;
 if (*out) { FUN_08ad3088(&DAT_08bef8f4); ++((int *)*out)[1]; FUN_08ad2810(&DAT_08bef8f4); }
 return out;
}

// 67 words differ; Os and O2 have the same mismatch, stack and register layout differ.
// near miss from lane lbp13c (unreviewed)
