/* LBPMATCH module=EBOOT.BIN start=0x08a9ae48 end=0x08a9aea8 symbol=FUN_08a9ae48 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3a, Claude Sonnet 5.5): FUN_08baa16c takes an argument (fields 0x10 and 0xc of the object, loaded into a0 in retail); exact match verified; names and types await human review. */
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

extern uint * DAT_08bf7dd8;
extern void FUN_08a9e0cc();
extern void FUN_08baa16c(uint);

void FUN_08a9ae48(void)
{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_08bf7dd8;
  if (DAT_08bf7dd8 != (uint *)0x0) {
    FUN_08baa16c(puVar1[4]);
    FUN_08baa16c(puVar1[3]);
    uVar2 = *puVar1;
    if (uVar2 != 0) {
      FUN_08a9e0cc(uVar2);
    }
    FUN_08a9e0cc((uint)puVar1);
  }
  DAT_08bf7dd8 = (uint *)0x0;
  return;
}
