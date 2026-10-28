/* LBPMATCH module=EBOOT.BIN start=0x0886c79c end=0x0886c854 symbol=FUN_0886c79c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef struct { void *p; int a,b,c,d; char e; } State; extern unsigned long long DAT_08be83e8; extern State DAT_08be8418; extern void FUN_08adb8a4(void*);
void FUN_0886c79c(int action, int id) { if(action==1) { if(id==65535) { if(++DAT_08be83e8==1) { DAT_08be8418.a=0; DAT_08be8418.p=0; DAT_08be8418.e=0; DAT_08be8418.b=0; DAT_08be8418.c=0; DAT_08be8418.d=0; } } } else if(action==0 && id==65535) { if(--DAT_08be83e8==0 && DAT_08be8418.p) FUN_08adb8a4(DAT_08be8418.p); } }




// Five words differ: zero-store scheduling order; 64-bit counter and branch logic otherwise match.
// near miss from lane lbp1a (unreviewed)
