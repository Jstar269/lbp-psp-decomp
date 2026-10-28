/* LBPMATCH module=EBOOT.BIN start=0x089cad58 end=0x089cad80 symbol=FUN_089cad58 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct ModeSource {
  char unk_00[0x24c];
  int mode;              /* +0x24c: 2 selects the other flag */
};

struct ModeRef {
  struct ModeSource *source;   /* +0 */
};

struct ByteFlags {
  char unk_00[0x1e];
  unsigned char unk_1e;
  unsigned char unk_1f;
  unsigned char unk_20;
};

/* Sets flag +0x20 when the source mode is 2, flag +0x1e otherwise; always clears +0x1f. */
void FUN_089cad58(struct ModeRef *ref, struct ByteFlags *flags)
{
  if (ref->source->mode == 2) {
    flags->unk_20 = 1;
  }
  else {
    flags->unk_1e = 1;
  }
  flags->unk_1f = 0;
}
