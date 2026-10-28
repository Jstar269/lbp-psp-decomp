/* LBPMATCH module=EBOOT.BIN start=0x08a6ba64 end=0x08a6baec symbol=FUN_08a6ba64 lang=c99 rodata=0x08babccc */
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

extern undefined4 DAT_08bf7194;
extern void FUN_08a3fad0(float param_1,int *param_2);

void FUN_08a6ba64(float param_1,int *param_2)
{
  FUN_08a3fad0(param_1,param_2);
  if (((char)param_2[0x71] == '\x01') &&
     (DAT_08bf7194 = param_1 * *(float *)(param_2[100] + 200) + DAT_08bf7194,
     6.2831855f <= DAT_08bf7194)) {
    DAT_08bf7194 = DAT_08bf7194 - 6.2831855f;
    return;
  }
  return;
}

// Primary profile initial candidate: 25 differing words; disassembly and diff retained in try/lane-work.
// near miss from lane lbp1b (unreviewed)
