/* LBPMATCH module=EBOOT.BIN start=0x0885b7f0 end=0x0885b86c symbol=FUN_0885b7f0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char DAT_08baf430, DAT_08bae6e0, DAT_08bedb94, DAT_08baec60;
extern void FUN_08a9e0c4(void *), FUN_08843f48(void *), FUN_0885c9f8(void *), FUN_08a9e0cc(void *);
void FUN_0885b7f0(void **p) {
 void **sub = p + 54;
 p[0] = &DAT_08baf430;
 sub[0] = &DAT_08bae6e0;
 if (sub[13] != &DAT_08bedb94 && sub[13]) FUN_08a9e0c4(sub[13]);
 FUN_08843f48(sub);
 p[0] = &DAT_08baec60;
 FUN_0885c9f8(p);

}


// One word differs: field load base a0 rather than s1 as in related 0x0885a3c4.
// near miss from lane lbp13b (unreviewed)
