/* LBPMATCH module=EBOOT.BIN start=0x08b8ceb8 end=0x08b8cf80 symbol=FUN_08b8ceb8 lang=c99 cc=gcc404xs-O2 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_08be4bf8;
extern struct { signed char flag, count; } DAT_08c15098;
extern void FUN_08b8ceac();
extern int FUN_08baa024();
extern void FUN_08baa02c();
extern int FUN_08baa11c();

void FUN_08b8ceb8(void)
{
  if (DAT_08c15098.flag == '\0') {
    int lock = FUN_08baa024();
    DAT_08c15098.count = DAT_08c15098.count + '\x01';
    if (DAT_08c15098.count == '\x01') {
      FUN_08baa02c(lock);
      FUN_08b8ceac();
      DAT_08c15098.flag = '\x01';
    }
    else {
      FUN_08baa02c(lock);
      while ((DAT_08c15098.flag == '\0' && (FUN_08baa11c(100), DAT_08c15098.flag == '\0'))) {
        FUN_08baa11c(100);
      }
    }
  }
  if (DAT_08be4bf8 < 0) {
    DAT_08be4bf8 = 0;
  }
  return;
}




// O2 6 differing words in wait-loop register choice and scheduling; Os 44; grouped signed flags and restored lock/sleep arguments.
// near miss from lane lbp8e (unreviewed)
