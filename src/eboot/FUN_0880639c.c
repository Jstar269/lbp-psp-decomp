/* LBPMATCH module=EBOOT.BIN start=0x0880639c end=0x08806440 symbol=FUN_0880639c lang=c99 */
/* Clone of src/eboot/FUN_08805ac8.c (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct View {
  const char *p;
  int len;
};
extern int DAT_08bec4ac;
extern const char DAT_08bab614[];
extern void *FUN_08b9eb88(void *d, int c, int n);
extern int FUN_08ba0868(char *d, int n, const char *fmt, ...);
extern int FUN_08a9b8a4(void *o, const char *s);
extern int FUN_08a9d790(struct View *v);

int FUN_0880639c(int unused, const char *name)
{
  char buf[64];
  struct View w;
  struct View v;
  FUN_08b9eb88(buf, 0, 64);
  FUN_08ba0868(buf, 64, DAT_08bab614, name, DAT_08bec4ac);
  DAT_08bec4ac = DAT_08bec4ac + 1;
  v.len = FUN_08a9b8a4(&v, buf);
  v.p = buf;
  int r = FUN_08a9d790(&v);
  FUN_08a9b8a4(&w, buf);
  return r;
}
