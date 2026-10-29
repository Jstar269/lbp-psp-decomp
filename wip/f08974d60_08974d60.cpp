/* LBPMATCH module=EBOOT.BIN start=0x08974d60 end=0x08974dc4 symbol=FUN_08974d60 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern float DAT_08bac1b4, DAT_08bab59c;
struct T { float duration, progress; unsigned char active; void update(float dt) { if (active) { float n; if (duration == 0.0f) n = DAT_08bac1b4; else n = dt / duration; progress = progress + n; if (DAT_08bab59c <= progress) { progress = DAT_08bab59c; active = 0; } } } };
struct S { char pad[20]; T t; };
extern "C" void FUN_08974d60(S *s, float dt) { s->t.update(dt); }
// 12 words differ in floating point branch and register scheduling; tested Os and O2 and inline member.
// near miss from lane lbp14b (unreviewed)
