/* LBPMATCH module=EBOOT.BIN start=0x08a3e6cc end=0x08a3e73c symbol=FUN_08a3e6cc lang=c99 */
extern void FUN_08a6b124(void *, int, int, int, int);
extern char DAT_08bc4d30, DAT_08bc4bf8;
extern float DAT_08bc4d74;
void FUN_08a3e6cc(char *p, int a, int b, int c) {
 FUN_08a6b124(p,a,b,1,c);
 *(void **)(p+588)=&DAT_08bc4d30;
 *(void **)p=&DAT_08bc4bf8;
 *(int *)(p+592)=-1;
 *(float *)(p+608)=DAT_08bc4d74;
 *(int *)(p+620)=0;
 p[596]=0;
 *(int *)(p+600)=0; *(int *)(p+604)=0; *(int *)(p+612)=0; *(int *)(p+616)=0;
}
// Twelve scheduling words differ in Os.
// near miss from lane lbp14a (unreviewed)
