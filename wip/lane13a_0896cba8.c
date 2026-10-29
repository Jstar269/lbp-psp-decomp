/* LBPMATCH module=EBOOT.BIN start=0x0896cba8 end=0x0896cc58 symbol=FUN_0896cba8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
extern char DAT_08bb8940;
extern void FUN_0896b21c(void *);
void FUN_0896cba8(char *p) {
 int i = 1; char *q = p + 24;
 FUN_0896b21c(p); *(void **)p = &DAT_08bb8940;
 do { char *n = q; i--;
  *(void **)n = n; *(void **)(q+4)=n; *(int *)(q+8)=0; *(int *)(q+12)=0;
  *(short *)(q+16)=0; *(short *)(q+18)=0; *(short *)(q+20)=-1; *(short *)(q+22)=-1; q += 24;
 } while (i != -1);
 *(short *)(p+82)=0; p[80]=0; *(short *)(p+90)=0; *(void **)(p+84)=p+48;
 *(short *)(p+98)=0; *(short *)(p+94)=0; *(short *)(p+96)=0; *(int *)(p+72)=0;
 *(short *)(p+102)=0; *(void **)(p+76)=p+48; p[88]=0; *(short *)(p+92)=0; *(short *)(p+100)=0;
}

// 21 differing words: loop and trailing stores differ in scheduling and addressing.
// near miss from lane lbp13a (unreviewed)
