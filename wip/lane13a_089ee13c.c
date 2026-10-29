/* LBPMATCH module=EBOOT.BIN start=0x089ee13c end=0x089ee1b4 symbol=FUN_089ee13c lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp13a, Codex GPT-6): structured the insertion condition; names and types await human review. */
extern char *FUN_089ed8c8(void *, unsigned *);
extern char *FUN_089edf5c(void *, char *, unsigned *);
char *FUN_089ee13c(char *p, unsigned *key) {
 unsigned item[2];
 char *n = FUN_089ed8c8(p, key);
 if (n == p + 4 || *key < *(unsigned *)(n + 16)) {
  item[0] = *key;
  item[1] = 0;
  n = FUN_089edf5c(p, n, item);
 }
 return n + 20;
}
// O2: one word differs, beq operands reversed; source operand order does not change encoding.
// near miss from lane lbp13a (unreviewed)
