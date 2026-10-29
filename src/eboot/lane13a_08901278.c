/* LBPMATCH module=EBOOT.BIN start=0x08901278 end=0x0890130c symbol=FUN_08901278 lang=c99 rodata=0x08bab5d8 */
/* Clone of src/eboot/lane13a_0890055c.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp13a, Codex GPT-6): corrected reference count decrement; exact match verified; names and types await human review. */
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

extern undefined * DAT_08bf7304;
extern void FUN_0891074c();
extern void FUN_08a2f7f8(float param_1,int param_2,int *param_3,char param_4);
extern undefined4 FUN_08a50fbc();

void FUN_08901278(int param_1)
{
  int iVar1;
  int *apiStack_20 [4];
  
  FUN_0891074c(param_1);
  FUN_08a50fbc();
  apiStack_20[0] = *(int **)(param_1 + 0x60);
  iVar1 = *(int *)(DAT_08bf7304 + 0x24c);
  if (apiStack_20[0] != (int *)0x0) {
    apiStack_20[0][1] = apiStack_20[0][1] + 1;
  }
  FUN_08a2f7f8(0.1f,iVar1,(int *)apiStack_20,'\0');
  if ((apiStack_20[0] != (int *)0x0) &&
     (--apiStack_20[0][1] == 0)) {
    (**(code **)(*apiStack_20[0] + 8))(apiStack_20[0]);
  }
  return;
}

