#ifndef LBP_RD3B_LIST_H
#define LBP_RD3B_LIST_H

/* Two-pointer link of a circular doubly linked list; an empty list is a link whose two pointers point at itself.
   The list header is a link embedded in the owning object. */
struct ListLink {
  struct ListLink *next;
  struct ListLink *prev;
};

/* 12-byte list node (the size handed to FUN_08adbc24 when a node is freed): the links, then a 32-bit key. */
struct KeyNode {
  struct KeyNode *next;
  struct KeyNode *prev;
  int key;
};

#endif
