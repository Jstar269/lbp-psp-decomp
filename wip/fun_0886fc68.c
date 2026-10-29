/* LBPMATCH module=EBOOT.BIN start=0x0886fc68 end=0x0886fe30 symbol=FUN_0886fc68 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void *FUN_08a9e838(int);
extern void FUN_088736d8(void *, int, void *);
extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
extern void *FUN_08adbb84(void *, int);
extern void FUN_08b88fac(void *, void *);
extern char *DAT_08be84ac;
extern char DAT_08bef8f4;
int FUN_0886fc68(unsigned *p, char *base, char *ctx) {
 char *src; void *obj; int *node; char *heap; int count;
 switch (*p) {
 case 0x4d4c564c: src=*(char **)(ctx+52); break;
 case 0x4d4f4349: src=*(char **)(ctx+56); break;
 case 0x4d544143: src=*(char **)(ctx+48); break;
 case 0x4d4a424f:
  obj=FUN_08a9e838(68); FUN_088736d8(obj,20,base+p[1]);
  heap=DAT_08be84ac; FUN_08ad3088(heap+32); node=FUN_08adbb84(heap,12); FUN_08ad2810(heap+32);
  if (node && obj) { node[2]=(int)obj; FUN_08ad3088(&DAT_08bef8f4); ((int *)obj)[1]++; FUN_08ad2810(&DAT_08bef8f4); }
  FUN_08b88fac(node,ctx+64);
  if (obj) { FUN_08ad3088(&DAT_08bef8f4); count=--((int *)obj)[1]; FUN_08ad2810(&DAT_08bef8f4); if (!count) (*(void (**)(void *))(*(char **)obj+4))(obj); }
  return 0;
 default: return 0;
 }
 __builtin_memcpy(base+p[1], *(char **)(src+20)+12, 20);
 return 0;
}
// 122 differing words; switch layout, register allocation and reference-counting shape differ. O2 worsens to 128.
// near miss from lane lbp13d (unreviewed)
