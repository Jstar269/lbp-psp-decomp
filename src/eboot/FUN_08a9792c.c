/* LBPMATCH module=EBOOT.BIN start=0x08a9792c end=0x08a97974 symbol=FUN_08a9792c lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_float8.h"

/* Reads eight floats from the stream into `out`, permuting them; returns the stream position after them. */
const float *FUN_08a9792c(const float *stream, struct Float8 *out)
{
  out->unk_0c = stream[0];
  out->unk_1c = stream[1];
  out->unk_10 = stream[2];
  out->unk_14 = stream[3];
  out->unk_18 = stream[4];
  out->unk_00 = stream[5];
  out->unk_04 = stream[6];
  out->unk_08 = stream[7];
  return stream + 8;
}
