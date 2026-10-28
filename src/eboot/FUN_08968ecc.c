/* LBPMATCH module=EBOOT.BIN start=0x08968ecc end=0x08968f1c symbol=FUN_08968ecc lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
/* The writer object keeps its output cursor in the second word of the buffer it points to. */
struct WordBuffer {
  unsigned int unk_00;
  unsigned int *cursor;
};

struct Writer {
  char pad[0x2c];
  struct WordBuffer *buffer;
};

/* Appends a fixed six-word record to the output buffer. */
void FUN_08968ecc(struct Writer *self)
{
  unsigned int *out;

  out = self->buffer->cursor;
  self->buffer->cursor = out + 6;
  out[0] = 0xc9000000;
  out[1] = 0xc6000105;
  out[2] = 0xc7000000;
  out[3] = 0x17000001;
  out[4] = 0xffffffff;
  out[5] = 0x23000001;
}
