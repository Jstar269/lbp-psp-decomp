/* Layout shared by a family of objects whose constructor-like function (the 0x180..0x1a0 block) looks up two keyed
   items through FUN_08a50fbc/FUN_08a52b38 and registers them. Only the accessed fields are named. */
#ifndef LBP_OBJ180LAYOUT_H
#define LBP_OBJ180LAYOUT_H

typedef struct Obj180 {
  char pad_000[0x180];
  unsigned int unk_180;
  unsigned int unk_184;
  unsigned int unk_188;
  unsigned int unk_18c;
  int *unk_190;
  char pad_194[8];
  unsigned int key_19c;   /* looked up through FUN_08a52b38 */
  unsigned int key_1a0;
} Obj180;

#endif
