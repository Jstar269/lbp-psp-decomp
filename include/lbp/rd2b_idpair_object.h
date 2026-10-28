#ifndef LBP_RD2B_IDPAIR_OBJECT_H
#define LBP_RD2B_IDPAIR_OBJECT_H

/* Tail of the object the FUN_08a9a5c8-initialised wrappers share. Fields +0x180..+0x18c are set up by a
   per-class helper, then +0x19c/+0x1a0 (two ids), +0x190 and the object itself are handed to the
   FUN_08a10f1c() singleton via FUN_08a115e0. Bytes before +0x180 belong to the base class. */
struct IdPairObject {
  char base[0x180];
  unsigned int unk_180;
  unsigned int unk_184;
  unsigned int unk_188;
  unsigned int unk_18c;
  unsigned int unk_190;
  char unk_194[8];
  unsigned int id_a;          /* +0x19c */
  unsigned int id_b;          /* +0x1a0 */
};

#endif
