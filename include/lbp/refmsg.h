/* Reference-counted message objects and the listener nodes they are dispatched to (EBOOT event dispatch code). */
#ifndef LBP_REFMSG_H
#define LBP_REFMSG_H

/* A message: built by FUN_08979514 (id, payload), released by FUN_08970b6c once its count drops to zero. */
typedef struct RefMsg {
  void *vtable;
  short alloc_size;   /* 16: size handed back to the allocator on release */
  short refcount;
  int id;             /* message id, e.g. 0x4a3b */
  int payload;
} RefMsg;

struct Listener;
/* Vtable slot 2 (offset 8): handle a message; a zero return stops the dispatch loop. Other slots are not decoded. */
typedef int (*ListenerHandleFn)(struct Listener *self, RefMsg **msg);

/* Vtable of a listener; read by the code as an array of handler slots (see Listener). */
typedef struct ListenerVtable {
  void *slot0;
  void *slot1;
  ListenerHandleFn handle;   /* offset 8 */
  void *slot3;
  void *slot4;
  void *slot5;
  ListenerHandleFn handle_slot6;   /* offset 0x18, same signature */
} ListenerVtable;

/* A listener on a singly linked list. */
typedef struct Listener {
  ListenerVtable *vtable;
  int unk_04;
  struct Listener *next;
} Listener;

/* The object that owns a listener list. */
typedef struct Dispatcher {
  int unk_00;
  int unk_04;
  Listener *first;
  int sender;         /* copied into each message's payload */
} Dispatcher;

#endif
