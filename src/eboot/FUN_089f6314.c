/* LBPMATCH module=EBOOT.BIN start=0x089f6314 end=0x089f631c symbol=FUN_089f6314 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_089f631c.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Forwards its seven remaining arguments to FUN_0897f498, prefixed by the pointer stored at offset 0x28 of self. */
struct Owner89f631c {
  char pad[0x28];
  int target;
};

extern void FUN_0897f498(int target, unsigned int a1, unsigned int a2, unsigned int a3,
                         unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);

void FUN_089f6314(struct Owner89f631c *self, unsigned int a1, unsigned int a2, unsigned int a3,
                  unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
  FUN_0897f498(self->target, a1, a2, a3, a4, a5, a6, a7);
}
