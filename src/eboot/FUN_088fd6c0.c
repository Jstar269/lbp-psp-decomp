/* LBPMATCH module=EBOOT.BIN start=0x088fd6c0 end=0x088fd730 symbol=FUN_088fd6c0 lang=c99 cc=gcc410-Os rodata=0x08baf1c0 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_08a2ff9c(0.3, 0, ...) with two values picked from the global state DAT_08bf7304: the word at +0x24c
   and an entry of the int array at +0x754 chosen through the table DAT_08bb59f8. */
struct GlobalState {
  char pad[0x24c];
  int value_24c;
  char pad2[0x754 - 0x250];
  int entries[(0x6698 - 0x754) / 4];   /* +0x754 */
  int row_6698;                        /* +0x6698: row selector, scaled by 4 */
};

struct Owner1c {
  char pad[0x1c];
  int column;                /* +0x1c */
};

extern int DAT_08bb59f8[];
extern struct GlobalState *DAT_08bf7304;
extern float FUN_08a2ff9c(float scale, float zero, int arg_a, int arg_b, unsigned char flag);
extern float FUN_08a50fbc();

void FUN_088fd6c0(struct Owner1c *self)
{
  FUN_08a50fbc();
  FUN_08a2ff9c(0.3f, 0, DAT_08bf7304->value_24c,
               DAT_08bf7304->entries[DAT_08bb59f8[DAT_08bf7304->row_6698 * 4 + self->column]], 0);
  return;
}
