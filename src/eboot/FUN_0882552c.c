/* LBPMATCH module=EBOOT.BIN start=0x0882552c end=0x08825584 symbol=FUN_0882552c lang=c99 cc=gcc410-Os rodata=0x08bab59c */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Three floats the curve is built from, reached through the pointer at +0x18 of the owner. */
struct CurveParams {
  float base;       /* [0] */
  float scale;      /* [1] */
  float divisor;    /* [2] */
};

struct CurveOwner {
  char unk_00[0x18];
  const struct CurveParams *params;   /* +0x18 */
};

extern float FUN_08b84c50(float base, float exponent);   /* looks like powf: (base, exponent) */

/* Exponential mapping: (base^(input / divisor) - 1) / (base - 1) * scale. */
float FUN_0882552c(float input, const struct CurveOwner *owner)
{
  const struct CurveParams *p;
  float base;
  float scale;
  float powered;

  p = owner->params;
  base = p->base;
  scale = p->scale;
  powered = FUN_08b84c50(base, input / p->divisor);
  return ((powered - 1.0f) / (base - 1.0f)) * scale;
}
