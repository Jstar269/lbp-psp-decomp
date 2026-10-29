/* LBPMATCH module=EBOOT.BIN start=0x08945ae8 end=0x08945b54 symbol=FUN_08945ae8 lang=c99 */
extern char DAT_08bb7270,DAT_08bb72c4,DAT_08bb72b0;
extern void FUN_08944bf0(void *), FUN_08a9c304(void *,void *), FUN_0894a258(void *);
void FUN_08945ae8(char *p) { int x[2]; FUN_08944bf0(p); *(void **)p=&DAT_08bb7270; x[0]=0; x[1]=0; FUN_08a9c304(p+72,x); *(int *)(p+96)=0; *(int *)(p+100)=0; FUN_0894a258(p+104); *(void **)(p+104)=&DAT_08bb72c4; *(void **)p=&DAT_08bb72b0; }

// Four words differ: final vtable stores scheduled in reverse order.
// near miss from lane lbp14a (unreviewed)
