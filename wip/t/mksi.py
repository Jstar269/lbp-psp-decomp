"""Generate a static-init source: python mksi.py start end gbase cc out count:data ..."""
import sys
start,end,gbase,cc,out=sys.argv[1:6]; holders=[tuple(x.split(':')) for x in sys.argv[6:]]
g=int(gbase,16)
L=[f"/* LBPMATCH module=EBOOT.BIN start={start} end={end} symbol=_Z41__static_initialization_and_destruction_0ii lang=c++ cc={cc} bss=0x{g:08x} rodata=0x08bab598 */",
   "/* NOTE */",
   'extern "C" void FUN_08adb8a4(void *p);',
   "struct Block { void *p; int f4; int f8; int fc; int f10; char f14; };"]
cnts=sorted({c for c,d in holders},reverse=True); datas=sorted({d for c,d in holders},reverse=True)
L.append("extern unsigned long long "+", ".join(f"DAT_{c}" for c in cnts)+";")
L.append("extern Block "+", ".join(f"DAT_{d}" for d in datas)+";")
L.append("template <class T> inline T dyn(T v) { return v; }")
import os
spec=os.environ.get("SI_GLOBALS")  # "addr:type:value,..." in definition order; default: the template's layout
if spec is not None:
    for item in filter(None, spec.split(",")):
        ad,ty,v=item.split(":"); L.append(f"{ty} DAT_{ad} = dyn({v});")
else:
    L.append(f"float DAT_{g+0x18:08x} = dyn(-3.40282347e38f);")
    for off,v in ((0x14,"9"),(0x10,"0xd"),(0xc,"0x19"),(0x8,"6"),(0x4,"0xf"),(0x0,"0xf")):
        L.append(f"int DAT_{g+off:08x} = dyn({v});")
if g == 0: L[0] = L[0].replace(" bss=0x00000000", "")
if spec == "": L.remove("template <class T> inline T dyn(T v) { return v; }")
ro=os.environ.get("SI_RODATA")
if ro: L[0]=L[0].replace("rodata=0x08bab598",f"rodata={ro}")
inl=""  # gcc404xs-Os inlines the holder ctor/dtor (always_inline no longer needed)
L.append("#define HOLDER(N, COUNT, DATA) \\")
L.append(f"struct N {{ {inl}N() {{ if (++COUNT == 1) {{ DATA.f8 = 0; DATA.fc = 0; DATA.f10 = 0; DATA.f4 = 0; DATA.p = 0; DATA.f14 = 0; }} }} \\")
L.append(f"           {inl}~N() {{ if (--COUNT == 0 && DATA.p != 0) FUN_08adb8a4(DATA.p); }} }};")
for i,(c,d) in enumerate(holders):
    L.append(f"HOLDER(H{i}, DAT_{c}, DAT_{d})")
for i in range(len(holders)):
    L.append(f"static H{i} h{i};")
open(out,'w',encoding='utf-8',newline='\n').write("\n".join(L)+"\n")
