/* LBPMATCH module=EBOOT.BIN start=0x08874024 end=0x0887408c symbol=FUN_08874024 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* zlib z_stream (zlib.h): 56 bytes, every member is one 32-bit word on the PSP. */
struct ZStream {
  const unsigned char *next_in;
  unsigned int avail_in;
  unsigned int total_in;
  unsigned char *next_out;
  unsigned int avail_out;
  unsigned int total_out;
  char *msg;
  void *state;
  void *zalloc;
  void *zfree;
  void *opaque;
  int data_type;
  unsigned int adler;
  unsigned int reserved;
};

/* An object that embeds a zlib inflate stream at +0xe8. */
struct InflateOwner {
  char unk_000[0xe8];
  struct ZStream strm;        /* +0xe8 */
  char unk_120[0x10188 - 0x120];
  int unk_10188;
};

#define MAX_WBITS 15

extern const char DAT_08bb05e8[];                 /* version string handed to inflateInit2_ */
extern int FUN_08ad58c4();                        /* zlib inflateInit2_(strm, windowBits, version, stream_size) */

void FUN_08874024(struct InflateOwner *self, int value)
{
  /* Default allocator and no input: the usual z_stream setup before inflateInit2_. */
  self->strm.zalloc = 0;
  self->strm.zfree = 0;
  self->strm.opaque = 0;
  self->strm.avail_in = 0;
  self->strm.next_in = 0;
  FUN_08ad58c4(&self->strm, MAX_WBITS, DAT_08bb05e8, sizeof(struct ZStream));
  self->unk_10188 = value << 1;
}
