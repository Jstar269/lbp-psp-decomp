#ifndef LBP_RD2B_FLOAT8_H
#define LBP_RD2B_FLOAT8_H

/* Eight floats in memory order. FUN_08a9792c reads them from a flat float stream and FUN_08a97974 writes
   them back; the two use the same permutation (stream order differs from the member order below). */
struct Float8 {
  float unk_00;
  float unk_04;
  float unk_08;
  float unk_0c;
  float unk_10;
  float unk_14;
  float unk_18;
  float unk_1c;
};

#endif
