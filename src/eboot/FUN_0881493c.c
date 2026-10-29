/* LBPMATCH module=EBOOT.BIN start=0x0881493c end=0x08814a08 symbol=FUN_0881493c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): list head typed as a two-pointer node struct, link and trailing field stores written in ascending offset order; exact match verified; names and types await human review. */
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

extern undefined4 DAT_08be84a0;
extern void FUN_08805edc();
extern void FUN_0880610c();
extern void FUN_08814734();
extern void FUN_08adbc24();

struct N { struct N *next; struct N *prev; };
void FUN_0881493c(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  struct N *n;
  struct N *next;
  struct N *head;

  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if ((puVar1 != (undefined4 *)0x0) && (*(uchar *)(puVar1 + 0x1c) == '\0')) {
    FUN_08814734(puVar1,'\x01','\x01');
    *(undefined4 *)(param_1 + 0x1a0) = 3;
    head = (struct N *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x1b0) = 2;
    *(undefined4 *)(param_1 + 0x19c) = 0;
    n = head->next;
    while (n != head) {
      next = n->next;
      FUN_08adbc24(DAT_08be84a0,(uint)n,0xc);
      n = next;
    }
    head->next = head;
    head->prev = head;
    FUN_0880610c(param_1 + 0x18);
    FUN_08805edc(param_1 + 0x58);
    *(undefined4 *)(param_1 + 0x1a8) = param_2;
    *(undefined4 *)(param_1 + 0x1ac) = param_3;
    *(undefined4 *)(param_1 + 0x1e4) = 3;
  }
}
