/* LBPMATCH module=EBOOT.BIN start=0x088dc4fc end=0x088dc578 symbol=FUN_088dc4fc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Sub {
  char pad_00[0x10];
  unsigned short unk_10;     /* index into the 0x34-byte record table */
};

struct Entry {
  char pad_00[0x18];
  struct Sub *unk_18;
};

struct Stack {
  char pad_00[0x1c];
  struct Entry **begin;      /* +0x1c */
  struct Entry **end;        /* +0x20: the top entry is end[-1] */
};

struct Record {
  char pad_00[8];
  unsigned int unk_08;
  char pad_0c[0x28];         /* records are 0x34 bytes */
};

struct Obj {
  char pad_00[0x160];
  struct Record *records;    /* +0x160 */
};

extern struct Stack *DAT_08beee0c;
extern int FUN_08a50fbc();
extern int FUN_08a52b38();

void FUN_088dc4fc(struct Obj *self)
{
  struct Entry *top;
  int arg;

  top = 0;
  if (DAT_08beee0c != 0 && DAT_08beee0c->begin != DAT_08beee0c->end) {
    top = DAT_08beee0c->end[-1];
  }
  arg = FUN_08a50fbc();
  FUN_08a52b38(arg, self->records[top->unk_18->unk_10].unk_08);
}
