/* LBPMATCH module=EBOOT.BIN start=0x08889454 end=0x08889670 symbol=FUN_08889454 lang=c99 rodata=0x08bb0e50 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
/* Bob Jenkins' lookup2 hash; FUN_08889330 is its mix(a, b, c) taking the three words by address. */
extern void FUN_08889330(unsigned *a, unsigned *b, unsigned *c);

unsigned FUN_08889454(const unsigned char *k, unsigned length, unsigned initval)
{
  unsigned a, b, c, len;

  a = b = 0x9e3779b9;
  c = initval;
  len = length;
  while (len >= 12) {
    a += k[0] + ((unsigned)k[1] << 8) + ((unsigned)k[2] << 16) + ((unsigned)k[3] << 24);
    b += k[4] + ((unsigned)k[5] << 8) + ((unsigned)k[6] << 16) + ((unsigned)k[7] << 24);
    c += k[8] + ((unsigned)k[9] << 8) + ((unsigned)k[10] << 16) + ((unsigned)k[11] << 24);
    FUN_08889330(&a, &b, &c);
    k += 12;
    len -= 12;
  }
  c += length;
  switch (len) {
  default: c += (unsigned)k[10] << 24;
  case 10: c += (unsigned)k[9] << 16;
  case 9: c += (unsigned)k[8] << 8;
  case 8: b += (unsigned)k[7] << 24;
  case 7: b += (unsigned)k[6] << 16;
  case 6: b += (unsigned)k[5] << 8;
  case 5: b += k[4];
  case 4: a += (unsigned)k[3] << 24;
  case 3: a += (unsigned)k[2] << 16;
  case 2: a += (unsigned)k[1] << 8;
  case 1: a += k[0];
  case 0: break;
  }
  FUN_08889330(&a, &b, &c);
  return c;
}
