/* LBPMATCH module=EBOOT.BIN start=0x088ce524 end=0x088ce628 symbol=FUN_088ce524 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct { int w[5]; } __attribute__((packed)) PKey;
typedef struct { int w[5]; } Key;
typedef struct Obj {
  Key key;
  char name[44];
  unsigned flags;
} Obj;
extern char DAT_08bb4318[];
extern int FUN_08ba0d98(const char *, const char *);
extern void FUN_088399bc(char *obj, int n, char *fmt, ...);

void FUN_088ce524(Obj *self, PKey key)
{
  PKey t = key;
  if (FUN_08ba0d98((const char *)self, (const char *)&t)) {
    FUN_088399bc(self->name, 17, DAT_08bb4318, key);
    self->flags |= 2;
    self->key = *(Key *)&key;
  }
}
// NEAR: retail keeps the unaligned-loaded 20-byte key in s1-s5 across the strcmp call, copies it to sp+20 (strcmp arg),
// and inside the branch stores it to sp+0 (a3 -> snprintf, read back into self->key after the call) and to sp+40 (dead copy).
// Ours keeps the key in memory at sp+0 and copies via v0 loads. Tried: packed by-value param with variadic by-value arg,
// pointer arg, aligned local Key copy; none reproduce the three-copy layout.
// near miss from lane lbp11a (unreviewed)
