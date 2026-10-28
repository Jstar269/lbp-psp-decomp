/* LBPMATCH module=EBOOT.BIN start=0x08a9da1c end=0x08a9db10 symbol=FUN_08a9da1c lang=c99 */
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

struct Entry { int count; int size; };
struct State { char pad[0x2e8]; struct Entry entries[1]; };
extern struct State DAT_08bf85f8;
extern undefined DAT_08bf88e4;

void FUN_08a9da1c(undefined4 param_1,int *param_2,int param_3)
{
  int iVar1;
  int local_1c [3];
  uint local_20;
  
  (**(code **)(*param_2 + 0x1c))(param_2,0xc);
  local_20 = 0;
  (**(code **)(*param_2 + 0x38))(param_2,&local_20,param_1);
  local_1c[0] = 0;
  (**(code **)(*param_2 + 0x3c))(param_2,local_1c,param_1);
  (**(code **)(*param_2 + 4))(param_2,param_1,local_20,0,0);
  iVar1 = param_3 * 0x40 + ((local_20 & 0xffff0000) + 0x20000000 >> 0x10);
  DAT_08bf85f8.entries[iVar1].count--;
  DAT_08bf85f8.entries[iVar1].size -= local_1c[0];
  return;
}

// Generated starting point; primary compiler comparison remains unmatched.

// Struct-based base address reduces mismatch to 19 words; array address and field scheduling remain different.
// near miss from lane lbp1c (unreviewed)
