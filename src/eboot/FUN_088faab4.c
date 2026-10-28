/* LBPMATCH module=EBOOT.BIN start=0x088faab4 end=0x088fab34 symbol=FUN_088faab4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Global object whose embedded sub-object at +0x750 is queried for two floats. */
struct GlobalObject {
  char unk_000[0x750];
  char sub_object[1];          /* +0x750: start of an embedded object (size not known here) */
};

struct Updater {
  char unk_00[4];
  int unk_04;                  /* non-zero: do the update */
};

extern struct GlobalObject *DAT_08bf7304;
extern float FUN_088f94f4(void *sub_object);
extern float FUN_088f94fc(void *sub_object);
extern void *FUN_08a50fbc();   /* returns a global pointer; its result is not used here */
extern void FUN_08a77e78(float first, float second, void *global_obj);

/* When enabled, hands the two floats read from the global object's sub-object to FUN_08a77e78. */
void FUN_088faab4(struct Updater *self)
{
  struct GlobalObject *global_obj;
  void *sub_object;
  float first;
  float second;

  if (self->unk_04 != 0) {
    FUN_08a50fbc();
    global_obj = DAT_08bf7304;
    sub_object = global_obj->sub_object;
    first = FUN_088f94f4(sub_object);
    second = FUN_088f94fc(sub_object);
    FUN_08a77e78(first, second, global_obj);
  }
}
