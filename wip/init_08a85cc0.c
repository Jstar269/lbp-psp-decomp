/* LBPMATCH module=EBOOT.BIN start=0x08a85cc0 end=0x08a85d30 symbol=FUN_08a85cc0 lang=c99 */
extern void FUN_08a6b124(void *, int, int, int, int);
extern char DAT_08bc8ce8; extern float DAT_08bab59c;
typedef struct { int a,b,c; } Triple;
void FUN_08a85cc0(char *p,int a,Triple *v,int c) {
 FUN_08a6b124(p,a,0,0,c);
 *(float *)(p+604)=DAT_08bab59c; *(void **)p=&DAT_08bc8ce8;
 *(Triple *)(p+588)=*v; p[600]=0;
}

// Thirteen words differ from saved-register allocation; struct copy matches ordering.
// near miss from lane lbp14a (unreviewed)
