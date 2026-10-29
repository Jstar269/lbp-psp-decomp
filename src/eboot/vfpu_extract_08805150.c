/* LBPMATCH module=EBOOT.BIN start=0x08805150 end=0x08805174 symbol=FUN_08805150 lang=c99 asm=vfpu */
/* Hand-written reconstruction from the disassembly (lane lbp15c, Codex GPT-6); exact match verified; names and types await human review. */
/* Original inline VFPU asm: repeated vector loads and scalar VFPU stores implement component extraction. */
void FUN_08805150(void *unused, const float *src, float *dst) {
 __asm__("lv.q C000, %1\n sv.s S000, %0" : "=m"(dst[0]) : "m"(*src));
 __asm__("lv.q C000, %1\n vmov.s S000, S001\n sv.s S000, %0" : "=m"(dst[1]) : "m"(*src));
 __asm__("lv.q C000, %1\n vmov.s S000, S002\n sv.s S000, %0" : "=m"(dst[2]) : "m"(*src));
}

