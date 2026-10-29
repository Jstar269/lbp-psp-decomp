/* LBPMATCH module=EBOOT.BIN start=0x089ed85c end=0x089ed8c8 symbol=FUN_089ed85c cc=gcc404xs-O2 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3c, Claude Sonnet 5.5): rewritten as a for loop over a node struct, cc=gcc404xs-O2; exact match verified; names and types await human review. */
struct Owner { int pad; int value; };
struct Entry { char pad[4]; struct Owner *owner; char name[0x50]; struct Entry *next; };
extern struct Entry *DAT_08bf374c;
extern int FUN_08ba0d98(const char *, const char *);

int FUN_089ed85c(const char *param_1)
{
  struct Entry *e;
  int sum = 0;
  for (e = DAT_08bf374c; e != 0 && FUN_08ba0d98(e->name, param_1) != 0; e = e->next) {
    sum += e->owner->value;
  }
  return sum;
}
