#ifndef LBP_RD2A_ENTRYTABLE_H
#define LBP_RD2A_ENTRYTABLE_H

/* Object holding a table of entry pointers and a 16-bit selector (-1 = none). Readers index the
   table with the selector, one of them with its negation. */
struct EntryTable {
  char unk_00[0x38];
  int *entries;        /* +0x38: array of entry pointers */
  short current;       /* +0x3c: selector into entries */
};

#endif
