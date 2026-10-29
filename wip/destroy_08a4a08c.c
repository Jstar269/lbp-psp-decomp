/* LBPMATCH module=EBOOT.BIN start=0x08a4a08c end=0x08a4a0f8 symbol=FUN_08a4a08c lang=c99 cc=gcc404xs-O2 */
extern char DAT_08bc5a10; extern unsigned char *DAT_08be8480; extern void FUN_08a49e54(void *); extern long long FUN_08a6ae78(void *);
void FUN_08a4a08c(int *p) { *p=(int)&DAT_08bc5a10; if(p[147] && p[147]!=3 && DAT_08be8480 && DAT_08be8480[4]) FUN_08a49e54(p); FUN_08a6ae78(p); }


// Five words differ: O2 duplicates epilogue after conditional call; Os block order differs.
// near miss from lane lbp14a (unreviewed)
