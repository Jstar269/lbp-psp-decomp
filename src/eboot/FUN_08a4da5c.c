/* LBPMATCH module=EBOOT.BIN start=0x08a4da5c end=0x08a4daec symbol=FUN_08a4da5c lang=c99 cc=gcc404xs-O2 */
/* Ghidra pseudocode (lbpgen.py tag gen) corrected by hand (lane lbp3d, Claude Sonnet 5.5): built with cc=gcc404xs-O2 (at -Os the recursion is inlined); plain for loop over the intrusive list instead of the nested while/break; exact match verified; names and types await human review. */
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


struct Node { struct Node *next; int pad[3]; int *obj; };
void FUN_08a4da5c(int param_1)
{
  struct Node *head = (struct Node *)(param_1 + 0x360);
  struct Node *n;
  for (n = head->next; n != head; n = n->next) {
    int *piVar1 = n->obj;
    (**(code **)(*piVar1 + 0x84))(piVar1,1);
    if (piVar1[0x11] == 0xd) FUN_08a4da5c((int)piVar1);
  }
}
