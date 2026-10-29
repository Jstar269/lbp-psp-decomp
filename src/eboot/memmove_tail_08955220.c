/* LBPMATCH module=EBOOT.BIN start=0x08955220 end=0x08955284 symbol=FUN_08955220 lang=c99 */
/* Clone of src/eboot/memmove_tail_08823238.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Buf { int a; int size; } Buf;
extern void *FUN_08b9e8cc(void *dst, void *src, int n);
void *FUN_08955220(Buf *b, char *dst, char *src)
{
  FUN_08b9e8cc(dst, src, b->size - (int)src);
  b->size -= (src - dst) & ~3;
  return dst;
}
