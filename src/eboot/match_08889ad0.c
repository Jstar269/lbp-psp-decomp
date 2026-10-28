/* LBPMATCH module=EBOOT.BIN start=0x08889ad0 end=0x08889b3c symbol=FUN_08889ad0 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g10) corrected by hand (lane lbp1b, Codex GPT-6): corrected byte signedness; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern void FUN_08baa464();
extern void FUN_08baa4bc();
extern void FUN_08baa4ec();
extern void FUN_08baa874();
extern void FUN_08baa97c();

void FUN_08889ad0(int param_1)
{
  if (*(unsigned char *)(param_1 + 8) != '\0') {
    FUN_08baa464();
    FUN_08baa4ec();
    FUN_08baa4bc();
    FUN_08baa874();
    FUN_08baa97c(262);
    FUN_08baa97c(261);
    FUN_08baa97c(260);
    FUN_08baa97c(259);
    *(undefined1 *)(param_1 + 8) = 0;
  }
  return;
}

