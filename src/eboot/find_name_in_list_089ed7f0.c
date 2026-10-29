/* LBPMATCH module=EBOOT.BIN start=0x089ed7f0 end=0x089ed85c symbol=FUN_089ed7f0 cc=gcc404xs-O2 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g8) corrected by hand (lane lbp3c, Claude Sonnet 5.5): rewritten as a for loop over a node struct (list scan with strcmp-like callee), cc=gcc404xs-O2; exact match verified; names and types await human review. */
struct Entry { char pad[8]; char name[0x50]; struct Entry *next; };
extern struct Entry *DAT_08bf374c;
extern int FUN_08ba0d98(const char *, const char *);

int FUN_089ed7f0(const char *param_1)
{
  struct Entry *e;
  for (e = DAT_08bf374c; e != 0; e = e->next) {
    if (FUN_08ba0d98(param_1, e->name) == 0) return 1;
  }
  return 0;
}
