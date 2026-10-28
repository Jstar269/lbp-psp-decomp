/* LBPMATCH module=EBOOT.BIN start=0x0887c1fc end=0x0887c238 symbol=FUN_0887c1fc lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Job {
  void *unk_00;
  unsigned int unk_04;
  unsigned int result;   /* +8: filled in from FUN_0887c14c */
};

extern int DAT_08bedba4;
extern unsigned int FUN_0887c14c(int arg0, void *arg1, unsigned int arg2);

/* Always returns 0; the call's result is stored in the job. */
int FUN_0887c1fc(struct Job *job)
{
  unsigned int result;

  result = FUN_0887c14c(DAT_08bedba4, job->unk_00, job->unk_04);
  job->result = result;
  return 0;
}
