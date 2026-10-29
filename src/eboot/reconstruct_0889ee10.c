/* LBPMATCH module=EBOOT.BIN start=0x0889ee10 end=0x0889ee64 symbol=FUN_0889ee10 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned char undefined;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned char byte;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned short ushort;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned int uint;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned long long ulonglong;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef long long longlong;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned char uchar;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned char bool;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned long long undefined8;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef int code();
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
#define true 1
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
#define false 0
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
#define ABS(x) ((x) < 0 ? -(x) : (x))
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned short undefined2;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
extern undefined1 * FUN_0889ecf8();
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
extern int FUN_08b9e714();
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
bool FUN_0889ee10(int *param_1)
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
{
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  byte *pbVar1;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  int iVar2;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  int iVar3;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  undefined1 auStack_20 [16];
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  iVar2 = param_1[2] - 0x10;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  iVar3 = *param_1;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  pbVar1 = (byte *)FUN_0889ecf8(iVar3,iVar2,auStack_20);
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  iVar2 = FUN_08b9e714((byte *)(iVar3 + iVar2),pbVar1,0x10);
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
  return iVar2 == 0;
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */
}
/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g2) corrected by hand (lane lbp5b, Codex GPT-6): compute the adjusted offset before the calls; exact match verified; names and types await human review. */

