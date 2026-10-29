/* LBPMATCH module=EBOOT.BIN start=0x08a356d8 end=0x08a359ac symbol=FUN_08a356d8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); names and types await human review. */
typedef struct { void *p; int a,b,c,d; char e; } State;
extern unsigned long long DAT_08be83e0, DAT_08be83e8, DAT_08be83f0;
extern State DAT_08be8400, DAT_08be8418, DAT_08be8430;
extern void FUN_08adb8a4(void *);
static void init(State *s) { s->p=0; s->e=0; s->b=0; s->c=0; s->d=0; s->a=0; }
void FUN_08a356d8(int mode, int id) {
 if (id != 65535) return;
 if (mode == 0) {
  if (--DAT_08be83e0 == 0 && DAT_08be8400.p) FUN_08adb8a4(DAT_08be8400.p);
  if (--DAT_08be83e8 == 0 && DAT_08be8418.p) FUN_08adb8a4(DAT_08be8418.p);
  if (--DAT_08be83f0 == 0 && DAT_08be8430.p) FUN_08adb8a4(DAT_08be8430.p);
 } else if (mode == 1) {
  if (++DAT_08be83f0 == 1) init(&DAT_08be8430);
  if (++DAT_08be83e8 == 1) init(&DAT_08be8418);
  if (++DAT_08be83e0 == 1) init(&DAT_08be8400);
 }
}

// Incomplete: VFPU initialization and scalar global stores are missing; 179 differing words. Counter decrement sequence matches structurally.
// near miss from lane lbp15b (unreviewed)
