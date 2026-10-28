/* LBPMATCH module=EBOOT.BIN start=0x08a4d56c end=0x08a4d5dc symbol=FUN_08a4d56c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Object torn down by FUN_08a4d56c; only the members it releases are named. */
struct TornDownObject {
  char unk_000[0x1e0];
  unsigned int registry_id;    /* +0x1e0: handed back to the FUN_08a50fbc() registry */
  char unk_1e4[8];
  void *unk_1ec;               /* released with FUN_088050b8 when set */
  char unk_1f0[4];
  char embedded_1f4[0x1c];     /* +0x1f4: embedded member torn down by FUN_08921a38 */
  void *unk_210;               /* released with FUN_088050b8 when set */
  char unk_214[4];
  int unk_218;
};

extern void FUN_088050b8();
extern void FUN_088bb890();
extern void FUN_08921a38();
extern void *FUN_08a50fbc();   /* returns a global registry pointer */
extern void FUN_08a537dc();    /* (registry, id) */
extern void FUN_08a9e0cc();    /* releases the object memory */

/* Releases the members of `obj`, then the object. The first argument is not used. */
void FUN_08a4d56c(void *unused, struct TornDownObject *obj)
{
  FUN_088bb890(obj->unk_218);
  FUN_08a537dc(FUN_08a50fbc(), obj->registry_id);
  if (obj->unk_210 != 0) {
    FUN_088050b8(obj->unk_210);
  }
  FUN_08921a38(obj->embedded_1f4);
  if (obj->unk_1ec != 0) {
    FUN_088050b8(obj->unk_1ec);
  }
  FUN_08a9e0cc(obj);
}
