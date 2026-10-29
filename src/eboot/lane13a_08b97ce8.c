/* LBPMATCH module=EBOOT.BIN start=0x08b97ce8 end=0x08b97d88 symbol=FUN_08b97ce8 lang=c99 cc=gcc404xs-O2 */
/* Clone of src/eboot/lane13a_08b8d018.c (lbpclone.py tag c20): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); exact match verified; names and types await human review. */
extern unsigned FUN_08b97cd0(void *), FUN_08b97cd8(void *), FUN_08b97ce0(void *);
extern void FUN_08b9ca68(void) __attribute__((noreturn));
unsigned FUN_08b97ce8(unsigned char encoding, void *ctx) {
 if (encoding == 255) return 0;
 switch (encoding & 0x70) {
 case 0: case 0x10: case 0x50: return 0;
 case 0x20: return FUN_08b97cd0(ctx);
 case 0x30: return FUN_08b97cd8(ctx);
 case 0x40: return FUN_08b97ce0(ctx);
 default: FUN_08b9ca68();
 }
}
