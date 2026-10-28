/* LBPMATCH module=EBOOT.BIN start=0x08978f04 end=0x08978f28 symbol=FUN_08978f04 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Owner {
  char pad_00[0xc];
  void *unk_0c;
  void **members;          /* table of member back pointers (indexed by Member::index) */
};

struct Member {
  char pad_00[8];
  void *owner;             /* the Owner this member is registered with */
  int index;               /* slot in owner->members that points back at this member */
  void *unk_10;
};

/* Register `member` with `owner`: remember the owner, copy owner->unk_0c and store the back pointer. */
void FUN_08978f04(struct Owner *owner, struct Member *member)
{
  void **members;

  members = owner->members;
  member->unk_10 = owner->unk_0c;
  members[member->index] = member;
  member->owner = owner;
}
