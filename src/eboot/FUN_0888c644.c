/* LBPMATCH module=EBOOT.BIN start=0x0888c644 end=0x0888c6a8 symbol=FUN_0888c644 lang=c99 cc=gcc410-Os rodata=0x08baefb0 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
extern struct ListEntry *FUN_0884364c();
extern struct ListEntry *FUN_088436b0();
extern int FUN_08ba0d98();

/* Item with a name string at +8. */
struct NamedItem {
  unsigned char unk_00[8];
  unsigned char name[1];   /* +8 */
};

/* Entry of the sequence walked by FUN_0884364c (first) and FUN_088436b0 (next). */
struct ListEntry {
  unsigned char unk_00[0x20];
  struct NamedItem *item;  /* +0x20 */
};

/* Counts the entries whose item name compares equal to "playRecord" (FUN_08ba0d98 returns 0 on equal). */
int FUN_0888c644(void *container)
{
  struct ListEntry *entry;
  int cmp;
  int count;

  count = 0;
  for (entry = FUN_0884364c(container); entry != 0; entry = FUN_088436b0(entry)) {
    cmp = FUN_08ba0d98(entry->item->name, (unsigned char *)"playRecord");
    count = count + (cmp == 0);
  }
  return count;
}
