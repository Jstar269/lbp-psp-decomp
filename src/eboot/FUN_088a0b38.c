/* LBPMATCH module=EBOOT.BIN start=0x088a0b38 end=0x088a0b98 symbol=FUN_088a0b38 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();

struct OwnedBuf {
  unsigned char unk_00[8];
  unsigned int buffer;       /* +8 */
  unsigned char unk_0c[8];
  unsigned char owns_buffer; /* +0x14: when set the buffer is released through FUN_08a9e0c4 */
};

/* Releases the object *slot points at (and its buffer when it owns one), then clears *slot. */
void FUN_088a0b38(struct OwnedBuf **slot)
{
  struct OwnedBuf *obj;

  obj = *slot;
  if (obj != 0) {
    if (obj->owns_buffer == 0) {
      obj->buffer = 0;
    }
    else {
      if (obj->buffer != 0) {
        FUN_08a9e0c4(obj->buffer);
      }
      obj->buffer = 0;
    }
    FUN_08a9e0cc(obj);
  }
  *slot = 0;
}
