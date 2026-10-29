/* LBPMATCH module=EBOOT.BIN start=0x088d6780 end=0x088d68c0 symbol=FUN_088d6780 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char DAT_08bee778[], *DAT_08beed14; extern char DAT_08beecb2;
extern void FUN_088d5f9c(void *,int,int);
void FUN_088d6780(char *p, char *arg) {
 unsigned flags, type; char *src=*(char **)(arg+16);
 *(int *)(p+56)=*(int *)(arg+8); __builtin_memcpy(p+80,src+12,20);
 *(short *)(p+126)=*(short *)(*(char **)(DAT_08beed14+452)+58);
 __builtin_memcpy(p+60,DAT_08bee778,20); FUN_088d5f9c(p,0,64);
 flags=*(unsigned *)p; type=*(unsigned *)(p+40); flags=(flags & 0xffe5ffff)|0x20; *(unsigned *)p=flags;
 if (type==3 || type==5 || type==4) DAT_08beecb2=1; else if (type!=2) *(unsigned *)p=flags|0x8000;
}
// Copy and flag scheduling need work.
// near miss from lane lbp13c (unreviewed)
