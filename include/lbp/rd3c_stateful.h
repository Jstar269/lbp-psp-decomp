#ifndef LBP_RD3C_STATEFUL_H
#define LBP_RD3C_STATEFUL_H

/* Object with a small state code at +0xc8 (0, 1, 2, ... ), as the two state-driven helpers
   FUN_088565c4 and FUN_088630a4 see it. Only the state word is named. */
struct Stateful {
  char pad[0xc8];
  int state;
};

#endif
