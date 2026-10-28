/* LBPMATCH module=EBOOT.BIN start=0x08a6514c end=0x08a65164 symbol=FUN_08a6514c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Object that owns a 0x100-element output buffer; only the buffer pointer at +0x27c is used. */
struct FormatTarget {
  char unk_000[0x27c];
  unsigned short *text_buf;   /* +0x27c: 16-bit characters (FUN_088399bc scales its count by 2) */
};

#define TEXT_BUF_LENGTH 0x100

extern const unsigned char DAT_08bb4794[];   /* format string for the call below */
extern void FUN_088399bc();                  /* printf-style: (buffer, length, format, args...) into 16-bit characters */

/* Formats the arguments into self->text_buf. The wrapper does not forward its 3rd and 4th arguments. */
void FUN_08a6514c(struct FormatTarget *self, unsigned int arg1, unsigned int skipped_3, unsigned int skipped_4,
                  unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5)
{
  FUN_088399bc(self->text_buf, TEXT_BUF_LENGTH, DAT_08bb4794, arg1, arg2, arg3, arg4, arg5);
}
