/* LBPMATCH module=EBOOT.BIN start=0x08b8f288 end=0x08b8f340 symbol=FUN_08b8f288 lang=c99 rodata=0x08bd9bac */
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

extern int FUN_08b8f24c();

undefined4 * FUN_08b8f288(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 *puVar2;
  
  switch(param_2) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 10:
  case 0x1b:
  case 0x24:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    if (param_3 != 0) goto switchD_08b8f2c8_caseD_23;
  default:
    break;
  case 8:
  case 9:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x21:
  case 0x25:
  case 0x26:
  case 0x29:
    iVar1 = param_3;
    goto joined_r0x08b8f2f4;
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x22:
    goto switchD_08b8f2c8_caseD_15;
  case 0x23:
switchD_08b8f2c8_caseD_23:
    iVar1 = param_4;
joined_r0x08b8f2f4:
    if (iVar1 != 0) {
switchD_08b8f2c8_caseD_15:
      puVar2 = (undefined4 *)FUN_08b8f24c(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = param_2;
        puVar2[1] = param_3;
        puVar2[2] = param_4;
        return puVar2;
      }
    }
  }
  return (undefined4 *)0x0;
}

// Initial primary-profile candidate: 41 differing words; see lane-work diff for details.
// near miss from lane lbp7b (unreviewed)
