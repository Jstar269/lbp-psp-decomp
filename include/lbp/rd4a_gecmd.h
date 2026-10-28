#ifndef LBP_RD4A_GECMD_H
#define LBP_RD4A_GECMD_H

/* PSP Graphics Engine PRIM command: opcode 0x04 in the top byte, primitive type in bits 16..18 and the vertex
   count in the low 16 bits. */
#define GE_CMD_PRIM_TRIANGLE_STRIP 0x04040000
#define GE_CMD_PRIM_SPRITES        0x04060000

/* Command list being written: the word at +4 is the write cursor. */
struct CmdList {
  unsigned int *unk_00;
  unsigned int *cursor;    /* +4: next free command word */
};

/* A draw call holder: a command list at +0x2c and the count OR-ed into the PRIM command at +0x3c. */
struct PrimEmitter {
  char unk_00[0x2c];
  struct CmdList *list;    /* +0x2c */
  char unk_30[0xc];
  unsigned int count;      /* +0x3c: vertex count (low 16 bits of the command) */
};

#endif
