/* LBPMATCH module=EBOOT.BIN start=0x089154cc end=0x08915604 symbol=FUN_089154cc lang=c99 */
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

extern undefined DAT_08bb6284;
extern undefined DAT_08bb62a8;
extern undefined DAT_08bb62d0;
extern undefined DAT_08bb62fc;
extern undefined DAT_08bb6320;
extern undefined DAT_08bb634c;
extern undefined DAT_08bb6374;
extern undefined DAT_08bb6398;
extern undefined DAT_08bb63c0;
extern undefined DAT_08bb63e4;
extern undefined4 DAT_08bef3f4;
extern undefined4 DAT_08bef3f8;
extern undefined4 DAT_08bef3fc;
extern undefined4 DAT_08bef404;
extern undefined4 DAT_08bef408;
extern undefined4 DAT_08bef40c;
extern undefined4 DAT_08bef410;
extern undefined4 DAT_08bef414;
extern undefined4 DAT_08bef418;
extern undefined4 DAT_08bef41c;
extern undefined4 FUN_089153d0();
extern void FUN_089196f4();
extern void FUN_0891a41c();
extern undefined * FUN_0891a58c();
extern undefined4 FUN_089f19c0();
extern void FUN_089f1a64();

void FUN_089154cc(int param_1)
{
  undefined *puVar1;
  
  FUN_089f1a64(6);
  DAT_08bef410 = FUN_089153d0(param_1,&DAT_08bb6284);
  DAT_08bef3fc = FUN_089153d0(param_1,&DAT_08bb62a8);
  DAT_08bef40c = FUN_089153d0(param_1,&DAT_08bb62d0);
  DAT_08bef418 = FUN_089153d0(param_1,&DAT_08bb62fc);
  DAT_08bef41c = FUN_089153d0(param_1,&DAT_08bb6320);
  DAT_08bef414 = FUN_089153d0(param_1,&DAT_08bb634c);
  DAT_08bef404 = FUN_089153d0(param_1,&DAT_08bb6374);
  DAT_08bef408 = FUN_089153d0(param_1,&DAT_08bb6398);
  DAT_08bef3f8 = FUN_089153d0(param_1,&DAT_08bb63c0);
  DAT_08bef3f4 = FUN_089153d0(param_1,&DAT_08bb63e4);
  puVar1 = FUN_0891a58c();
  FUN_0891a41c((int)puVar1);
  puVar1 = FUN_0891a58c();
  FUN_089196f4((int)puVar1);
  FUN_089f19c0();
  return;
}

// Primary profile: 3 aligned words differ; final call lacks retail argument load. Passing 6 matched bytes but callee does not consume it, so source intent is unproven.
// near miss from lane lbp1b (unreviewed)
