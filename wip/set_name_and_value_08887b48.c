/* LBPMATCH module=EBOOT.BIN start=0x08887b48 end=0x08887b8c symbol=FUN_08887b48 lang=c99 */
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
typedef float undefined4;

extern char * FUN_08ba10e8();

struct Named { char name[0x80]; char flag; float value; };

void FUN_08887b48(float param_1,struct Named *param_2,char *param_3)
{
  FUN_08ba10e8(param_2->name,param_3,0x80);
  param_2->flag = 1;
  param_2->value = param_1;
  param_2->name[0x7f] = 0;
}
// 2 words differ: retail issues mov.s $f20,$f12 before li a2,128, ours li first (scheduler order of entry move vs call-arg setup).
// tried: struct form, float param first/middle/last, store permutations: no change
// near miss from lane lbp3c (unreviewed)
