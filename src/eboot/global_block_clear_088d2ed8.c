/* LBPMATCH module=EBOOT.BIN start=0x088d2ed8 end=0x088d2fcc symbol=FUN_088d2ed8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp2b, DeepSeek through Freebuff): retail zeroes DAT_08beeca8, DAT_08beecaa, DAT_08beecb0 and DAT_08beecb2 with sb, but the translation declared them undefined4/undefined2, so give each the byte type its store width shows (the other externs already match: ca4 is a real int); exact match verified; names and types await human review. */
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

extern undefined DAT_08bee7b4;
extern undefined DAT_08beeb60;
extern undefined4 DAT_08beeca4;
extern undefined DAT_08beeca8;
extern undefined DAT_08beeca9;
extern undefined DAT_08beecaa;
extern undefined DAT_08beecab;
extern undefined DAT_08beecaf;
extern undefined DAT_08beecb0;
extern undefined DAT_08beecb1;
extern undefined DAT_08beecb2;
extern undefined * DAT_08beecb4;
extern void FUN_088050b8();
extern uint * FUN_08b9eb88();

void FUN_088d2ed8(void)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_08beecb4;
  if (DAT_08beecb4 != 0) {
    piVar2 = *(int **)(DAT_08beecb4 + 100);
    *(undefined4 *)(DAT_08beecb4 + 100) = 0;
    if (piVar2 != (int *)0x0) {
      FUN_088050b8(piVar2);
    }
    piVar2 = *(int **)(iVar1 + 0x68);
    *(undefined4 *)(iVar1 + 0x68) = 0;
    if (piVar2 != (int *)0x0) {
      FUN_088050b8(piVar2);
    }
    if (*(int **)(iVar1 + 0x68) != (int *)0x0) {
      FUN_088050b8(*(int **)(iVar1 + 0x68));
    }
    piVar2 = *(int **)(iVar1 + 100);
    if (piVar2 != (int *)0x0) {
      FUN_088050b8(piVar2);
    }
    DAT_08beecb4 = 0;
  }
  FUN_08b9eb88(&DAT_08beeb60,0xff,0x144);
  DAT_08beeca4 = 0;
  DAT_08beecb2 = 0;
  DAT_08beecb1 = 0;
  DAT_08beecb0 = 0;
  DAT_08beecaf = 0;
  DAT_08beecab = 0;
  DAT_08beecaa = 0;
  DAT_08beeca9 = 0;
  DAT_08beeca8 = 0;
  FUN_08b9eb88((uint *)&DAT_08bee7b4,0,0x3ac);
  return;
}
