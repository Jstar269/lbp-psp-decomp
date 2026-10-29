/* LBPMATCH module=EBOOT.BIN start=0x088b2ecc end=0x088b2f74 symbol=FUN_088b2ecc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp7a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct { char pad[12]; unsigned flags; } Item;
typedef struct { char pad[24]; int active; } Global;
typedef struct { char pad[406]; unsigned char a,b; } State;
extern Global DAT_08bf85f8;
extern State *FUN_089ecaa8(void);
extern void FUN_089f19c0(int);
extern void FUN_089f1a64(int);
extern void FUN_08a9e1a8(void);
extern void FUN_08a9f1dc(void);
void FUN_088b2ecc(int unused, Item **p) {
 if ((*p)->flags & 1) {
  if (!DAT_08bf85f8.active) { FUN_089f1a64(3); FUN_08a9f1dc(); FUN_089f19c0(3); }
 } else if (DAT_08bf85f8.active) FUN_08a9e1a8();
 if ((*p)->flags & 8) { State *s=FUN_089ecaa8(); if (!s->b) s->a=1; }
}
