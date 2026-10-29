/* LBPMATCH module=EBOOT.BIN start=0x08a9a9d0 end=0x08a9aa98 symbol=FUN_08a9a9d0 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp3c, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++'s std::find for int* (random-access __find, four-way unrolled loop plus switch on the remainder). */
extern "C" int *FUN_08a9a9d0(int *first, int *last, const int *val)
{
  int trip = (last - first) >> 2;
  for (; trip > 0; --trip) {
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
    if (*first == *val) return first;
    ++first;
  }
  switch (last - first) {
  case 3:
    if (*first == *val) return first;
    ++first;
  case 2:
    if (*first == *val) return first;
    ++first;
  case 1:
    if (*first == *val) return first;
    ++first;
  case 0:
  default:
    return last;
  }
}
