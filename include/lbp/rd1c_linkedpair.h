#ifndef LBP_RD1C_LINKEDPAIR_H
#define LBP_RD1C_LINKEDPAIR_H

/* Fields at +0x190..+0x1a0 of the object the four FUN_08a99694 wrappers share: a pointer and two
   ids that are looked up through FUN_08a50fbc()/FUN_08a52b38() and registered with FUN_08a12ec0. */
struct LinkedPairObject {
  char unk_000[0x190];
  int *unk_190;               /* +0x190: forwarded unchanged */
  char unk_194[8];
  unsigned int id_a;          /* +0x19c */
  unsigned int id_b;          /* +0x1a0 */
};

#endif
