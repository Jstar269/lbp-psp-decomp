/* LBPMATCH module=EBOOT.BIN start=0x0889d3a4 end=0x0889d408 symbol=FUN_0889d3a4 lang=c99 */
/* Clone of src/eboot/memmove_tail_08823238.c (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Buf { int a; int size; } Buf;
extern void *FUN_08b9e8cc(void *dst, void *src, int n);
void *FUN_0889d3a4(Buf *b, char *dst, char *src)
{
  FUN_08b9e8cc(dst, src, b->size - (int)src);
  b->size -= (src - dst) & ~3;
  return dst;
}
