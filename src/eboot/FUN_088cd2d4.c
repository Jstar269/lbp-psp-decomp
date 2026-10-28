/* LBPMATCH module=EBOOT.BIN start=0x088cd2d4 end=0x088cd31c symbol=FUN_088cd2d4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

typedef struct Dst {
  char pad_00[0x36];
  unsigned short unk_36;
  unsigned short unk_38;
  char pad_3a[6];
  unsigned int flags;   /* bit 2 is set whenever unk_36 or unk_38 changes */
} Dst;

typedef struct Src {
  char pad_00[0x40];
  unsigned int unk_40;
  unsigned int unk_44;
} Src;

/* Copy src->unk_44 into dst->unk_38 and src->unk_40 into dst->unk_36 (as 16-bit values), flagging each change. */
void FUN_088cd2d4(Dst *dst, Src *src)
{
  unsigned int value;

  if ((unsigned int)dst->unk_38 == src->unk_44) {
    value = src->unk_40;
  }
  else {
    dst->unk_38 = (short)src->unk_44;
    dst->flags = dst->flags | 2;
    value = src->unk_40;
  }
  if (dst->unk_36 != value) {
    dst->unk_36 = (short)value;
    dst->flags = dst->flags | 2;
  }
  return;
}
