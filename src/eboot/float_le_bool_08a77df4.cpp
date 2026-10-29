/* LBPMATCH module=EBOOT.BIN start=0x08a77df4 end=0x08a77e1c symbol=FUN_08a77df4 lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp4d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: a bool local set true and cleared when the float compare fails (gives the retail li v0,0 / andi v0,v0,1 tail). */
extern "C" float DAT_08bef16c;
struct Obj { char pad[800]; float v; };
extern "C" bool FUN_08a77df4(Obj *o)
{
    bool r = true;
    if (!(o->v <= DAT_08bef16c)) r = false;
    return r;
}
