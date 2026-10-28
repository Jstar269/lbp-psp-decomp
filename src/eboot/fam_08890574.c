/* LBPMATCH module=EBOOT.BIN start=0x08890574 end=0x08890624 symbol=FUN_08890574 lang=c99 */
/* Clone of src/eboot/fam_0884a91c.c (lbpclone.py tag c15): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ref { void **vtable; int count; } Ref;
extern char DAT_08bef8f4[]; extern void FUN_08ad3088(void *),FUN_08ad2810(void *);
Ref **FUN_08890574(Ref **dst,Ref **src) { Ref *r=*src,*old; if(r) { FUN_08ad3088(DAT_08bef8f4); ++r->count; FUN_08ad2810(DAT_08bef8f4); } old=*dst; *dst=r; if(old) { int c; FUN_08ad3088(DAT_08bef8f4); c=--old->count; FUN_08ad2810(DAT_08bef8f4); if(!c) ((void (*)(Ref *))old->vtable[1])(old); } return dst; }

