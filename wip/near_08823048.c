/* LBPMATCH module=EBOOT.BIN start=0x08823048 end=0x088230a0 symbol=FUN_08823048 lang=c99 cc=gcc171-Os rodata=0x08bac164 rodata=0x08bac164 */
/* Hand-written reconstruction from the disassembly (lane lbp3a, Claude Sonnet 5.5); near miss, 2 word(s) differ; names and types await human review. */
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

extern undefined * FUN_089ecaa8();

float FUN_08823048(void)
{
  undefined *puVar1;
  
  puVar1 = FUN_089ecaa8();
  return (float)*(uint *)(*(int *)(puVar1 + 0x1b4) + 0xf4) / 986832.0f;
}
// needs cc=gcc171-Os (unsigned->float via cvt branch pair; gcc404xs adds a nop; neighbour 0x088231d8 is also gcc171-Os) and rodata=0x08bac164
// differs: epilogue order, retail 'addiu sp,sp,16; jr ra; div.s' (div.s in the delay slot), ours 'div.s; jr ra; addiu' - tried temp locals, (float)986832; same with gcc131/gcc171x
// near miss from lane lbp3a (unreviewed)
