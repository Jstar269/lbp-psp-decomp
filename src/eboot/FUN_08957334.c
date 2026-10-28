/* LBPMATCH module=EBOOT.BIN start=0x08957334 end=0x08957390 symbol=FUN_08957334 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Rec {
  unsigned int tag;
};

/* Tags are four-character codes; read big-endian they are MLVL, MJBO, MOCI and MTAC. */
#define TAG_MLVL 0x4d4c564c
#define TAG_MJBO 0x4d4a424f
#define TAG_MOCI 0x4d4f4349
#define TAG_MTAC 0x4d544143

extern void FUN_08957244();

/* Hands records with one of the four known tags to FUN_08957244; always returns 0.
   The control flow is the original compare tree, kept as is because it determines the code. */
int FUN_08957334(struct Rec *rec, unsigned int arg1, unsigned int arg2)
{
  unsigned int tag;
  unsigned int other;

  tag = rec->tag;
  if (tag != TAG_MLVL) {
    other = TAG_MJBO;
    if (TAG_MLVL < tag) {
      if (tag == TAG_MOCI) goto known_tag;
      other = TAG_MTAC;
    }
    if (tag != other) {
      return 0;
    }
  }
known_tag:
  FUN_08957244(rec, arg1, arg2);
  return 0;
}
