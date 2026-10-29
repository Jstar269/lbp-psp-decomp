/* LBPMATCH module=EBOOT.BIN start=0x088b6094 end=0x088b6128 symbol=FUN_088b6094 lang=c99 */
extern int FUN_08a50fbc(void);
extern void FUN_08a51eb8(int, int);
void FUN_088b6094(int p, int item, unsigned char flag) {
 int count=*(int *)(p+0xe8), i;
 if (count >= 100) return;
 for (i=0; i<count; i++) {
  if (*(int *)(p+0xec+i*4)==item) return;
 }


 *(int *)(p+0xec+count*4)=item;
 *(unsigned char *)(p+0x27c+(*(int *)(p+0xe8))++)=flag;
 FUN_08a51eb8(FUN_08a50fbc(),item);
}



// Revisit: 20 words differ; corrected integer return and loop, postincrement; branch layout and count reload differ.
// near miss from lane lbp8f (unreviewed)
