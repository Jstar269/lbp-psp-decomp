/* LBPMATCH module=EBOOT.BIN start=0x08968e00 end=0x08968e24 symbol=FUN_08968e00 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
struct ChannelState {
  unsigned char value;   /* the only byte copied */
  char unk_01[11];
};

struct ChannelSet {
  char unk_00[0x48];
  struct ChannelState channels[4];   /* +0x48, stride 0xc */
};

/* Copies the first byte of each of the four 12-byte entries from `src` to `dst`. */
void FUN_08968e00(struct ChannelSet *dst, struct ChannelSet *src)
{
  dst->channels[0].value = src->channels[0].value;
  dst->channels[1].value = src->channels[1].value;
  dst->channels[2].value = src->channels[2].value;
  dst->channels[3].value = src->channels[3].value;
}
