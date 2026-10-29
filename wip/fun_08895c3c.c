/* LBPMATCH module=EBOOT.BIN start=0x08895c3c end=0x08895dc0 symbol=FUN_08895c3c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char *DAT_08be84ac;
extern int FUN_08ba0d98(void *,const void *); extern void FUN_08b88fc8(void *), FUN_08b88fac(void *,void *), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08adbc24(void *,void *,int); extern char *FUN_08adbb84(void *,int);
void FUN_08895c3c(char *self,const char *key,unsigned char add) {
 char *head=self+28, *p=*(char **)head, *pool, *lock;
 while (p!=head && FUN_08ba0d98(p+8,key)) p=*(char **)p;
 if (p==head) {
  if (!add) return;
  pool=DAT_08be84ac; lock=pool+32; FUN_08ad3088(lock); p=FUN_08adbb84(pool,28); FUN_08ad2810(lock);
  if (p+8) __builtin_memcpy(p+8,key,20); FUN_08b88fac(p,head);
 } else if (!add) { FUN_08b88fc8(p); pool=DAT_08be84ac; lock=pool+32; FUN_08ad3088(lock); FUN_08adbc24(pool,p,28); FUN_08ad2810(lock); }
}
// List traversal and branch layout differ.
// near miss from lane lbp13c (unreviewed)
