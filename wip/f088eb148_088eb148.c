/* LBPMATCH module=EBOOT.BIN start=0x088eb148 end=0x088eb1cc symbol=FUN_088eb148 lang=c99 */
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

extern char DAT_08beeddc;
extern int FUN_088e6de4();
extern int FUN_088e7b30();
typedef struct { int p; } Iter;
extern void FUN_088eb018(void *, Iter, Iter);
extern int FUN_08b89838();

void FUN_088eb148(uint *param_1)
{
  int iVar1;
  int iVar2;
  int local_18;
  int local_1c;
  uint local_20;
  
  local_20 = *param_1;
  iVar1 = FUN_088e6de4(&DAT_08beeddc,&local_20);
  local_18 = FUN_088e7b30(&DAT_08beeddc,&local_20);
  for (iVar2 = iVar1; iVar2 != local_18; iVar2 = FUN_08b89838(iVar2)) {
  }
  local_1c = iVar1;
  FUN_088eb018(&DAT_08beeddc,(Iter){iVar1},(Iter){local_18});
  return;
}



// Nine words differ due to missing two stack stores for iterator temporaries; aggregate-by-value C did not reproduce them.
// near miss from lane lbp13b (unreviewed)
