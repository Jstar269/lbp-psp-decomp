/* LBPMATCH module=EBOOT.BIN start=0x08a6c5d4 end=0x08a6c6a8 symbol=FUN_08a6c5d4 lang=c99 cc=gcc402x-O2 rodata=0x08bc7bf8 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
struct MoviePlayback {
  char unk_00[0x98];
  int looping;          /* +0x98: non-zero is passed on as a flag */
  char path[1];         /* +0x9c: inline C string, the movie file name */
};

struct PathObject {
  int unk[8];           /* 32-byte temp built from the path by FUN_08a9c164, destroyed by FUN_08a9bff8 */
};

extern void FUN_089597a8();   /* (player, &path, flag, 0, credits, 0, credits) */
extern void *FUN_0895a96c();  /* the movie player */
extern void FUN_08a9bfc0();
extern void FUN_08a9bff8();
extern void FUN_08a9c164();   /* build a PathObject from a C string */
extern int FUN_08ba0d98();    /* strcmp-style three-way compare of two C strings */

/* Starts movie playback for the file named at +0x9c; the credits movie gets two extra flags set. */
void FUN_08a6c5d4(struct MoviePlayback *self)
{
  int flag;
  void *player;
  struct PathObject path;

  FUN_08a9c164(&path, self->path);
  FUN_08a9bfc0(&path);
  flag = self->looping != 0;
  if (FUN_08ba0d98(self->path, "movies/90_credits_mov_eu.bik") == 0) {
    player = FUN_0895a96c();
    FUN_089597a8(player, &path, flag, 0, 1, 0, 1);
    FUN_08a9bff8(&path);
    return;
  }
  player = FUN_0895a96c();
  FUN_089597a8(player, &path, flag, 0, 0, 0, 0);
  FUN_08a9bff8(&path);
}
