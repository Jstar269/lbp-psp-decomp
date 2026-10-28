/* Record initialised by FUN_088d469c and FUN_088d47b4 (0xe0 bytes); layout from the stores of those two functions,
   field names are offsets where the use is not known. */
#ifndef LBP_TAGGED_REC_H
#define LBP_TAGGED_REC_H

/* Eight-byte element of TaggedRec::entries. */
struct TaggedRecEntry {
  unsigned char byte0;
  unsigned char byte1;
  unsigned short half2;
  unsigned int word4;
};

struct TaggedRec {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  unsigned int unk_0c;
  unsigned int unk_10;
  unsigned short unk_14;
  unsigned short unk_16;
  unsigned short unk_18;
  unsigned short unk_1a;
  unsigned int tag;               /* set to 0x31324546, the bytes "FE21" in memory */
  unsigned int unk_20;
  unsigned int unk_24;
  unsigned int mode;              /* set to 3 */
  unsigned int unk_2c;
  unsigned int unk_30;
  unsigned int unk_34;
  unsigned int unk_38;            /* set to 0xffff */
  unsigned int block_3c[5];       /* cleared with memset, 0x14 bytes */
  unsigned int block_50[5];       /* cleared with memset, 0x14 bytes */
  unsigned int unk_64;
  unsigned int unk_68;
  unsigned int unk_6c;
  unsigned int unk_70;
  unsigned int unk_74;
  unsigned int unk_78;
  unsigned short unk_7c;          /* set to 0xffff */
  unsigned short unk_7e;
  unsigned short unk_80;
  unsigned short unk_82;          /* set to 0xff */
  unsigned char bytes_84[10];     /* filled with 0xff */
  unsigned char unk_8e;
  unsigned char unk_8f;
  struct TaggedRecEntry entries[10];
};

#endif
