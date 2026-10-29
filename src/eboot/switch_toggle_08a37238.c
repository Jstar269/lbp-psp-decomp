/* LBPMATCH module=EBOOT.BIN start=0x08a37238 end=0x08a372bc symbol=FUN_08a37238 lang=c99 cc=gcc404xs-O2 rodata=0x08bc462c */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
void FUN_08a37238(int *p, float *f, unsigned char flip, int mode)
{
  if (flip != 0) {
    int s = *p;
    *f = -*f;
    switch (s) {
    case 0:
    case 6:
      if (mode != 1 && mode != 3)
        *p = 1;
      break;
    case 1:
      *p = 0;
      break;
    case 2:
      *p = 3;
      break;
    case 3:
      *p = 2;
      break;
    }
  }
}
// cc=gcc404xs-O2 (batch hint Os was wrong): jump-table switch with duplicated jr ra; rodata= jump table.
