/* LBPMATCH module=EBOOT.BIN start=0x088d286c end=0x088d2918 symbol=FUN_088d286c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp10a, Claude Sonnet 5.5); exact match verified; names and types await human review. Unaligned 20-byte load from __builtin_memcpy of the source pointer (lwl/lwr). */
typedef struct S5 { char c; char pad[3]; int w[4]; } S5;

extern S5 DAT_08bee778;
extern char DAT_08bee790[];
extern char DAT_08bb4318[];
extern unsigned char DAT_08beecb1;
extern void FUN_088399bc(char *obj, int n, char *fmt, S5 *arg);

void FUN_088d286c(const void *p)
{
  S5 tmp;
  __builtin_memcpy(&tmp, p, 20);
  if (!DAT_08beecb1 && tmp.c) {
    DAT_08bee778 = tmp;
    FUN_088399bc(DAT_08bee790, 17, DAT_08bb4318, &tmp);
    DAT_08beecb1 = 1;
  }
}
