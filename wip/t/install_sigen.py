import json,pathlib,sys
d=json.load(open(sys.argv[1])); n=0
for r in d:
    if r['status']!='EXACT': continue
    f=pathlib.Path(r['source']); s=f.read_text(encoding='utf-8')
    tmpl='src/eboot/static_init_08804948.cpp' if 'cc=gcc404xs-Os' in s.split('\n',1)[0] else 'src/eboot/static_init_089f8e28.cpp'
    note=(f"/* Template instance of {tmpl} (a Hand-written reconstruction), written by wip/t/sigen.py from this function's "
          "disassembly (which holders, in which order, and where its globals live); exact match verified; names and types await human review. */")
    s=s.replace("/* NOTE */",note,1)
    dst=pathlib.Path('src/eboot')/f.name; assert not dst.exists(), dst
    dst.write_text(s,encoding='utf-8',newline='\n'); n+=1
print(n)
