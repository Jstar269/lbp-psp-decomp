/* LBPMATCH module=EBOOT.BIN start=0x0887c28c end=0x0887c310 symbol=FUN_0887c28c lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp3c, Claude Sonnet 5.5): modelled the map node's value as a struct with a count and a slot; exact match verified; names and types await human review. */
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

extern int FUN_0887c238();
extern void FUN_0887d580();
extern void FUN_0888b8c4();
extern void FUN_0888b8cc();
extern uint FUN_08ad16f0();

struct Entry { int pad0; int pad1; int count; int slot; };
struct EntryNode { char pad[0x14]; struct Entry value; };

void FUN_0887c28c(int param_1,undefined4 *param_2)
{
  struct EntryNode *node;
  uint local_20 [4];
  
  FUN_0888b8c4(param_1 + 0x104);
  local_20[0] = FUN_08ad16f0();
  node = (struct EntryNode *)FUN_0887c238(param_1 + 0x1a8,local_20);
  struct Entry *e = &node->value;
  e->count = e->count - 1;
  if (e->count == 0) {
    e->slot = 0;
  }
  FUN_0887d580(param_2);
  FUN_0888b8cc(param_1 + 0x104);
  return;
}
