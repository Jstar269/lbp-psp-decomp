/* LBPMATCH module=EBOOT.BIN start=0x0894f5bc end=0x0894f62c symbol=FUN_0894f5bc lang=c99 */
extern void *FUN_08a9e838(int);
extern void FUN_089503ec(void *);
extern char DAT_08bb78f8, DAT_08bb7930, DAT_08bb7964;
int FUN_0894f5bc(char *self) {
 void **p = FUN_08a9e838(16);
 p[0] = &DAT_08bb78f8;
 FUN_089503ec(p + 1);
 p[0] = &DAT_08bb7930;
 *(int *)(self + 172) = 16;
 p[1] = &DAT_08bb7964;
 *(void ***)(self + 168) = p;
 return p != 0;
}
// Seven words differ: return-null optimization and store scheduling; C reconstruction tried.
// near miss from lane lbp14a (unreviewed)
