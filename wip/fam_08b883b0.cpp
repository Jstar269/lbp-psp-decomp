/* LBPMATCH module=EBOOT.BIN start=0x08b883b0 end=0x08b884b0 symbol=FUN_08b883b0 lang=c++ cc=gcc404x-Os */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
extern "C" { extern char DAT_08c11078[], DAT_08bd8b18[]; void FUN_08b8ac1c(char**,char*,char*), FUN_08b89180(void*,char**), FUN_08b8aa38(void*,void*), FUN_08b8dc60(void*,void*,void*) __attribute__((noreturn)); void *FUN_08b8ccc0(int); int FUN_08b8cbbc(int*,int); void FUN_08b893f0(); }
extern "C" void FUN_08b883b0(char *s) { char *str; char alloc; FUN_08b8ac1c(&str,s,&alloc); void *p=FUN_08b8ccc0(8); FUN_08b89180(p,&str); if(str-12!=DAT_08c11078 && FUN_08b8cbbc((int*)(str-4),-1)<1) FUN_08b8aa38(str-12,&alloc); FUN_08b8dc60(p,DAT_08bd8b18,(void*)FUN_08b893f0); }
// Retail includes exception cleanup paths; explicit calls alone leave 59 differing words.
// near miss from lane lbp1a (unreviewed)
