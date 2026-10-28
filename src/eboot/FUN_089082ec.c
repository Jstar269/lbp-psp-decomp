/* LBPMATCH module=EBOOT.BIN start=0x089082ec end=0x08908304 symbol=FUN_089082ec lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Five-word record. */
struct Record5 {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  unsigned int unk_0c;
  unsigned int unk_10;
};

/* Fills the five words in order of arguments; the last one is stored first (as retail does). */
void FUN_089082ec(struct Record5 *rec, unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3,
                  unsigned int v4)
{
  rec->unk_10 = v4;
  rec->unk_00 = v0;
  rec->unk_04 = v1;
  rec->unk_08 = v2;
  rec->unk_0c = v3;
}
