/* LBPMATCH module=EBOOT.BIN start=0x088a7e88 end=0x088a7f34 symbol=FUN_088a7e88 lang=c99 cc=gcc402t-Os rodata=0x08bb301c */
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

extern float FUN_08b840bc(float param_1);

void FUN_088a7e88(float param_1,float param_2,float param_3,undefined4 param_4,int *param_5)
{
  undefined1 *puVar1;
  float fVar2;
  
  puVar1 = (undefined1 *)*param_5;
  fVar2 = FUN_08b840bc(param_1 * 127.5f);
  *puVar1 = (char)(int)fVar2;
  *param_5 = (int)(puVar1 + 1);
  fVar2 = FUN_08b840bc(param_2 * 127.5f);
  puVar1[1] = (char)(int)fVar2;
  *param_5 = (int)(puVar1 + 2);
  fVar2 = FUN_08b840bc(param_3 * 127.5f);
  puVar1[3] = 0;
  puVar1[2] = (char)(int)fVar2;
  *param_5 = (int)(puVar1 + 4);
  return;
}

// profile sweep: 22 differing words left; kept the generator key (normalising was worse or equal).
// near miss from lane lbp2d (unreviewed)
