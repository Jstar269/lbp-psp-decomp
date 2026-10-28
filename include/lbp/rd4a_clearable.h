#ifndef LBP_RD4A_CLEARABLE_H
#define LBP_RD4A_CLEARABLE_H

/* Block whose reset routine zeroes a flag byte and ten words (two per-class copies share this layout). */
struct ClearableBlock {
  unsigned int unk_00;
  unsigned char flag_04;
  char unk_05[0x4f];
  unsigned int unk_54;
  unsigned int unk_58;
  unsigned int unk_5c;
  unsigned int unk_60;
  unsigned int unk_64;
  unsigned int unk_68;
  unsigned int unk_6c;
  unsigned int unk_70;
};

#endif
