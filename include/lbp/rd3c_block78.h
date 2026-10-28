#ifndef LBP_RD3C_BLOCK78_H
#define LBP_RD3C_BLOCK78_H

/* State block (at least 0x88 bytes) cleared field by field by the two reset functions FUN_08a559b4 and
   FUN_08a559ec (same shape; only the fields they touch are named). */
struct Block78 {
  unsigned int unk_00;
  unsigned char unk_04;
  char pad_05[0x4f];
  unsigned int unk_54;
  unsigned int unk_58;
  unsigned int unk_5c;
  unsigned int unk_60;
  unsigned int unk_64;
  unsigned int unk_68;
  unsigned int unk_6c;
  unsigned int unk_70;
  unsigned int unk_74;
  unsigned int unk_78;
  char pad_7c[8];
  unsigned int unk_84;
};

#endif
