#ifndef LBP_RD1C_RELTABLE_H
#define LBP_RD1C_RELTABLE_H

/* Holder of an offset table: FUN_0891d6e4(&holder->table_ptr) style lookups read it. */
struct RelTableHolder {
  char unk_00[0xa8];
  unsigned int *table_ptr;      /* +0xa8: passed to FUN_0891d6e4, which returns the word it points at */
};

/* Object with two optional RelTableHolder links at +0x2a4 and +0x2a8. */
struct RelTableOwner {
  char unk_00[0x2a4];
  struct RelTableHolder *holder_a;   /* +0x2a4 */
  struct RelTableHolder *holder_b;   /* +0x2a8 */
};

#endif
