/* LBPMATCH module=EBOOT.BIN start=0x0883fa44 end=0x0883fa68 symbol=FUN_0883fa44 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
struct Config {
  char unk_000[0x24c];
  int mode;                 /* +0x24c: 1 selects the early-out below */
};

struct Context {
  struct Config *config;    /* +0 */
};

struct Target {
  char unk_000[0x108];
  unsigned char flag;       /* +0x108 */
};

extern unsigned int FUN_0883f904();

/* When context->config->mode is 1 only sets target->flag; otherwise forwards everything to FUN_0883f904
   (target is passed twice, arguments 3..8 unchanged). */
void FUN_0883fa44(struct Context *context, struct Target *target, unsigned int arg3, unsigned int arg4,
                  unsigned int arg5, unsigned int arg6, unsigned int arg7, unsigned int arg8)
{
  if (context->config->mode == 1) {
    target->flag = 1;
    return;
  }
  FUN_0883f904(target, target, arg3, arg4, arg5, arg6, arg7, arg8);
  return;
}
