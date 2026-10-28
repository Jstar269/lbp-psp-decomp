/* LBPMATCH module=EBOOT.BIN start=0x08a97974 end=0x08a979bc symbol=FUN_08a97974 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_float8.h"

/* Inverse of FUN_08a9792c: writes the eight floats of `in` to the stream in stream order and returns
   the position after them. */
float *FUN_08a97974(const struct Float8 *in, float *stream)
{
  stream[0] = in->unk_0c;
  stream[1] = in->unk_1c;
  stream[2] = in->unk_10;
  stream[3] = in->unk_14;
  stream[4] = in->unk_18;
  stream[5] = in->unk_00;
  stream[6] = in->unk_04;
  stream[7] = in->unk_08;
  return stream + 8;
}
