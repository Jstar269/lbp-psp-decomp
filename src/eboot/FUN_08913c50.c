/* LBPMATCH module=EBOOT.BIN start=0x08913c50 end=0x08913cf8 symbol=FUN_08913c50 lang=c99 cc=gcc402t-Os rodata=0x08bb61f8 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Returns the value in slot `index` (0..14) of the table at offset 0x84 of the object self->inner; 0x8000 when index is out of range. */
struct Inner08913c50 {
  char pad[0x84];
  unsigned int slot_84;
  unsigned int slot_88;
  unsigned int slot_8c;
  unsigned int slot_90;
  unsigned int slot_94;
  unsigned int slot_98;
  unsigned int slot_9c;
  unsigned int slot_a0;
  unsigned int slot_a4;
  unsigned int slot_a8;
  unsigned int slot_ac;
  unsigned int slot_b0;
  unsigned int slot_b4;
  unsigned int slot_b8;
  unsigned int slot_bc;
};

struct Owner08913c50 {
  char pad[0x3c];
  struct Inner08913c50 *inner;
};

unsigned int FUN_08913c50(struct Owner08913c50 *self, unsigned int index)
{
  unsigned int result;
  struct Inner08913c50 *inner;

  result = 0x8000;  /* default for an out-of-range index */
  if (index < 0xf) {
    inner = self->inner;
    switch (index) {
    case 0:
      result = inner->slot_84;
      break;
    case 1:
      result = inner->slot_88;
      break;
    case 2:
      result = inner->slot_8c;
      break;
    case 3:
      result = inner->slot_90;
      break;
    case 4:
      result = inner->slot_94;
      break;
    case 5:
      result = inner->slot_98;
      break;
    case 6:
      result = inner->slot_9c;
      break;
    case 7:
      result = inner->slot_a0;
      break;
    case 8:
      result = inner->slot_a4;
      break;
    case 9:
      result = inner->slot_a8;
      break;
    case 10:
      result = inner->slot_ac;
      break;
    case 11:
      result = inner->slot_b0;
      break;
    case 12:
      result = inner->slot_b4;
      break;
    case 13:
      result = inner->slot_b8;
      break;
    case 14:
      result = inner->slot_bc;
    }
  }
  return result;
}
