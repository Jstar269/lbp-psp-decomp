/* LBPMATCH module=EBOOT.BIN start=0x08a38fa4 end=0x08a39144 symbol=FUN_08a38fa4 lang=c99 */
/* Preliminary reconstruction; not an exact match. */
typedef struct Obj { int pad[2]; int refs; int pad2[2]; } Obj;
extern void *DAT_08be84a8; extern char DAT_08babbc0[];
extern void FUN_08a995d8(void *, int, int, void **, void **);
extern Obj *FUN_08aaab30(void *, char *);
extern void FUN_08ad3088(void *); extern void FUN_08ad2810(void *); extern void FUN_088050b8(Obj *);
void FUN_08a38fa4(char *self) {
 void *a, *b; Obj *p, *old; unsigned int flags; int side;
 FUN_08a995d8(self, *(int *)(self+412), *(int *)(self+416), &a, &b);
 side = *(float *)((char *)a+136) >= *(float *)((char *)b+136);
 flags = *(unsigned int *)(self+420); flags = (flags & ~1u) | side; *(unsigned int *)(self+420)=flags;
 p = FUN_08aaab30(DAT_08be84a8, DAT_08babbc0);
 if (p) { FUN_08ad3088((char *)p+20); ++p->refs; FUN_08ad2810((char *)p+20); FUN_08ad3088((char *)p+20); ++p->refs; FUN_08ad2810((char *)p+20); }
 if (side) { old=*(Obj **)(self+384); *(Obj **)(self+384)=p; if(old) FUN_088050b8(old); if(p) FUN_088050b8(p); *(float *)(self+404)=*(float *)(self+432); }
 else { old=*(Obj **)(self+388); *(Obj **)(self+388)=p; if(old) FUN_088050b8(old); if(p) FUN_088050b8(p); *(float *)(self+408)=*(float *)(self+432); }
}

// 101 differing words, 78/104 words at gcc404xs-Os; O2 also 101 differing words.
// Preliminary C scalar comparison does not reproduce retail VFPU vector comparison; duplicated branch bodies are also merged. Investigate original VFPU inline asm and C++ reference lifetime.
// near miss from lane lbp15b (unreviewed)
