/* LBPMATCH module=EBOOT.BIN start=0x08a38920 end=0x08a38984 symbol=FUN_08a38920 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd4a_serial.h"

extern void FUN_0895541c();
extern void FUN_08a34774();
extern void FUN_08a55f00();
extern void FUN_08a55fbc();
extern void FUN_08a560c0();

/* Chunk routine for tag "TLOB": begins the chunk, hands the object's three sub-blocks on, then the closing call. */
void FUN_08a38920(struct SerialObject *self,int *stream)
{
  FUN_08a34774(self,stream,FOURCC('T','L','O','B'));
  FUN_08a55f00(stream,self->block_19c);
  FUN_08a55fbc(stream,self,self->block_1a8);
  FUN_08a560c0(stream,self->block_1b4);
  FUN_0895541c(stream);
  return;
}
