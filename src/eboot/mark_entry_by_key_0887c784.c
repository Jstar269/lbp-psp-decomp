/* LBPMATCH module=EBOOT.BIN start=0x0887c784 end=0x0887c808 symbol=FUN_0887c784 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): modelled the container as a struct with an embedded red-black tree and a node struct; exact match verified; names and types await human review. */
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

extern void FUN_0888b8c4();
extern void FUN_0888b8cc();

struct NodeBase { int color; struct NodeBase *parent; struct NodeBase *left; struct NodeBase *right; };
struct TreeNode { struct NodeBase base; int pad; unsigned char flag; unsigned char padb[3]; int key; };
struct Tree { int cmp; struct NodeBase header; int count; };
struct Owner { char pad[0x104]; int lock; char pad2[0x1a8 - 0x108]; struct Tree tree; };
extern struct NodeBase *FUN_08b89838(struct NodeBase *);

void FUN_0887c784(struct Owner *param_1,int *param_2)
{
  struct NodeBase *iVar1;
  int iVar2;
  
  FUN_0888b8c4(&param_1->lock);
  iVar2 = *param_2;
  if (-1 < iVar2) {
    struct Tree *t = &param_1->tree;
    for (iVar1 = t->header.left; iVar1 != &t->header; iVar1 = FUN_08b89838(iVar1)) {

      if (((struct TreeNode *)iVar1)->key == iVar2) {
        ((struct TreeNode *)iVar1)->flag = 1;
        break;
      }
    }
  }
  FUN_0888b8cc(&param_1->lock);
  return;
}
