/* LBPMATCH module=EBOOT.BIN start=0x088ea660 end=0x088ea6f0 symbol=FUN_088ea660 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned char undefined;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned char byte;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned short ushort;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned int uint;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned long long ulonglong;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef long long longlong;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned char uchar;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned char bool;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned long long undefined8;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef int code();
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
#define true 1
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
#define false 0
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
#define ABS(x) ((x) < 0 ? -(x) : (x))
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned short undefined2;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern undefined DAT_088e62a8;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern undefined DAT_088ea060;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern undefined4 DAT_08be85fc;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern undefined * FUN_08970dbc();
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern void FUN_089ead84();
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
extern undefined * FUN_089ecaa8();
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
void FUN_088ea660(int param_1)
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
{
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  undefined *puVar1;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  undefined *puVar2;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  undefined *puVar3;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  puVar1 = FUN_08970dbc(DAT_08be85fc,0x312);
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  puVar2 = FUN_08970dbc(DAT_08be85fc,0x313);
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  puVar3 = FUN_089ecaa8();
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  FUN_089ead84(puVar3,puVar1,puVar2,0x7f,(int)&DAT_088e62a8,(int)&DAT_088ea060,0);
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  *(uint *)(param_1 + 0xd0) = (*(uint *)(param_1 + 0xd0) | 0x2000) & 0xffffbfff;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
  return;
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */
}
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */

/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp5b, Codex GPT-6): order flag operations; exact match verified; names and types await human review. */

