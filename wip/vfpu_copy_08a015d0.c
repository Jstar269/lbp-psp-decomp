/* LBPMATCH module=EBOOT.BIN start=0x08a015d0 end=0x08a01660 symbol=FUN_08a015d0 lang=c99 cc=gcc404xs-O2 asm=vfpu */
/* Hand-written reconstruction from the disassembly (lane lbp15c, Codex GPT-6); names and types await human review. */
/* Original inline VFPU asm: vector load/store blocks copy temporary vectors around ordinary scalar code. */
typedef struct { float v[4]; } Vec;
extern float FUN_089fed84(void *,void *,Vec *,Vec *,Vec *,int *);
int FUN_08a015d0(void *a, void *b, char *out) {
 int n[4]; Vec y,x,z; float f=FUN_089fed84(b,a,&x,&y,&z,n);
 if(f>0) return 0;
 __asm__("lv.q C000, %1\n sv.q C000, %0":"=m"(*(Vec *)(out+48)):"m"(z));
 *(int *)(out+72)=n[0];
 __asm__("lv.q C000, %1\n sv.q C000, %0":"=m"(*(Vec *)(out+16)):"m"(y));
 *(float *)(out+64)=-f;
 __asm__("lv.q C000, %1\n sv.q C000, %0":"=m"(*(Vec *)(out+32)):"m"(x));
 return 1;
}

// Nine words differ at gcc404xs-O2: scalar negation and VFPU load/store scheduling. Os has 21 differing words and a shared epilogue.
// near miss from lane lbp15c (unreviewed)
