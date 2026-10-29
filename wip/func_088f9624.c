/* LBPMATCH module=EBOOT.BIN start=0x088f9624 end=0x088f9670 symbol=FUN_088f9624 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); names and types await human review. */
extern const float DAT_08bab59c,DAT_08bb4f80,DAT_08bb4f84;
float FUN_088f9624(float x){float v=DAT_08bb4f80-x; if(v<0) v=0; v=v/DAT_08bb4f84; if(DAT_08bab59c<v) v=DAT_08bab59c; return v;}
// O2 differs by nine words in constant scheduling and first clamp branch; Os differs by 14.
// near miss from lane lbp14c (unreviewed)
