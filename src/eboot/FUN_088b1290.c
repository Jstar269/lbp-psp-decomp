/* LBPMATCH module=EBOOT.BIN start=0x088b1290 end=0x088b12b0 symbol=FUN_088b1290 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08882980.c (lbpclone.py tag r-rd4b): addresses substituted; exact match verified; names and types await human review. */
extern void *DAT_08beee0c;
extern void FUN_088edfe8(void *arg);

/* Calls FUN_088edfe8 on DAT_08beee0c when it is set. */
void FUN_088b1290(void)
{
  if (DAT_08beee0c != 0) {
    FUN_088edfe8(DAT_08beee0c);
    return;
  }
  return;
}
