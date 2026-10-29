/* LBPMATCH module=EBOOT.BIN start=0x088cd084 end=0x088cd2d4 symbol=FUN_088cd084 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct { char b[20]; } Key;
typedef struct { char pad[61]; unsigned char count; char pad2[2]; unsigned flags; char pad3[1012]; char entries[250][16]; } Obj;
extern void FUN_089757c0(int);
extern void *FUN_088d7f9c(void);
extern void FUN_088f71f0(void *, char);
void FUN_088cd084(Obj *o, const Key *p, unsigned char add) {
 Key key; unsigned i, j = 0; __builtin_memcpy(&key, p, 20);
 if (add) { FUN_089757c0(65); if (o->count >= 250) return; __builtin_memcpy(o->entries[o->count++], key.b, 16); }
 else { FUN_089757c0(66); for (i=0; i<o->count; i++) { for (j=0; j<16 && o->entries[i][j]==key.b[j]; j++); if (j==16) { --o->count; __builtin_memcpy(o->entries[i], o->entries[o->count], 16); break; } } if (j != 16) return; }
 o->flags |= 2; FUN_088f71f0(FUN_088d7f9c(), 0);
}

// Near: stack temporaries and block scheduling differ; the natural memcpy form does not reproduce the retail frame.
// near miss from lane lbp15d (unreviewed)
