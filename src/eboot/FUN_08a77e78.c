/* LBPMATCH module=EBOOT.BIN start=0x08a77e78 end=0x08a77ea4 symbol=FUN_08a77e78 lang=c99 cc=gcc410-Os rodata=0x08bc4a70 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Starts an angle ramp: converts `degrees` to radians as the target, and stores the per-step rate (target minus
   the current angle at +0x684) divided by `divisor`. */
#define DEG_TO_RAD 0.017453292f

struct AngleRamp {
  char pad[0x680];
  unsigned char active;      /* +0x680 */
  char pad2[3];
  float current;             /* +0x684 */
  float target;              /* +0x688 */
  float rate;                /* +0x68c */
};

void FUN_08a77e78(float degrees, float divisor, struct AngleRamp *ramp)
{
  ramp->active = 1;
  ramp->target = degrees * DEG_TO_RAD;
  ramp->rate = (degrees * DEG_TO_RAD - ramp->current) / divisor;
  return;
}
