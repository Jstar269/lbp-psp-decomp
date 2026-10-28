/* LBPMATCH module=EBOOT.BIN start=0x0882d5a0 end=0x0882d5c8 symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc=gcc404xs-Os bss=0x08bed9f0 rodata=0x08bab598 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. C++ static initialisation of a single global initialised at run time to -FLT_MAX (dyn() keeps it dynamic, as retail stores it here); no holders. */
template <class T> inline T dyn(T v) { return v; }
float DAT_08bed9f0 = dyn(-3.40282347e38f);
