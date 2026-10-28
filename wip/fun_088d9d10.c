/* LBPMATCH module=EBOOT.BIN start=0x088d9d10 end=0x088d9d44 symbol=FUN_088d9d10 lang=c99 */
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

extern undefined4 DAT_08beed14;
extern undefined4 FUN_088d9b28();

int FUN_088d9d10(uint *param_1,int param_2,int param_3)
{
  return FUN_088d9b28(DAT_08beed14,param_1,param_2,param_3);

}


// Primary compiler tail-calls; retail has a frame. Three arguments corrected; 13 words differ.
// near miss from lane lbp1d (unreviewed)
