#ifndef LBP_RD3A_FLAGS298_H
#define LBP_RD3A_FLAGS298_H

/* Object reached through the +4 pointer of the callers' struct; only three byte flags are read. */
struct FlagObj298 {
  unsigned char unk_00[0x6c];
  unsigned char flag_6c;             /* +0x6c */
  unsigned char unk_6d[0x298 - 0x6d];
  unsigned char flag_298;            /* +0x298 */
  unsigned char unk_299[0x2b7 - 0x299];
  unsigned char flag_2b7;            /* +0x2b7 */
};

/* Struct whose +4 word points at a FlagObj298 (may be null). */
struct FlagObj298Ref {
  unsigned int unk_00;
  struct FlagObj298 *target;         /* +4 */
};

#endif
