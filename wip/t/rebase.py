import re,pathlib,sys
src=pathlib.Path(sys.argv[1]); out=pathlib.Path(sys.argv[2]); exemplar=sys.argv[3]; tag=sys.argv[4]
out.mkdir(exist_ok=True); n=0
for f in sorted(src.glob('*.cpp')):
    s=f.read_text(encoding='utf-8')
    defs=[int(a,16) for a in re.findall(r'^(?:float|int) DAT_([0-9a-f]{8}) =',s,re.M)]
    s=re.sub(r'bss=0x[0-9a-f]+',f'bss=0x{min(defs):08x}',s,count=1)
    head,note,rest=s.split('\n',2)
    note=(f"/* Clone of {exemplar} (lbpclone.py tag {tag}): addresses substituted, and the header's bss= rebased by hand "
          "to this copy's lowest global (lbpclone.py keeps the exemplar's); exact match verified; names and types await human review. */")
    (out/f.name).write_text(head+'\n'+note+'\n'+rest,encoding='utf-8',newline='\n'); n+=1
print(n)
