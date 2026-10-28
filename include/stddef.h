#ifndef LBP_STDDEF_NOTE
# define LBP_STDDEF_NOTE
/* Project-authored stddef.h for the 32-bit little-endian PSP (Allegrex; ILP32 ABI of psp-gcc 3.3.3).
   Written from ISO C 7.17 and the type widths of that ABI. It contains no compiler vendor text.
   A header that needs only some of the types defines __need_size_t, __need_ptrdiff_t, __need_wchar_t,
   __need_wint_t or __need_NULL before including this file (the convention newlib's headers use);
   an include without any of them defines the full ISO set. */
#endif

#if defined(__need_size_t) || defined(__need_ptrdiff_t) || defined(__need_wchar_t) \
    || defined(__need_wint_t) || defined(__need_NULL)
# define LBP_STDDEF_PARTIAL 1
#else
# define LBP_STDDEF_PARTIAL 0
# define __need_size_t
# define __need_ptrdiff_t
# define __need_wchar_t
# define __need_NULL
#endif

#if defined(__need_size_t) && !defined(LBP_SIZE_T_DEFINED)
# define LBP_SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#if defined(__need_ptrdiff_t) && !defined(LBP_PTRDIFF_T_DEFINED)
# define LBP_PTRDIFF_T_DEFINED
typedef int ptrdiff_t;
#endif

#if defined(__need_wchar_t) && !defined(LBP_WCHAR_T_DEFINED)
# define LBP_WCHAR_T_DEFINED
# ifndef __cplusplus
typedef int wchar_t;
# endif
#endif

#if defined(__need_wint_t) && !defined(LBP_WINT_T_DEFINED)
# define LBP_WINT_T_DEFINED
typedef unsigned int wint_t;
#endif

#if defined(__need_NULL)
# undef NULL
# define NULL ((void *)0)
#endif

#if !LBP_STDDEF_PARTIAL && !defined(offsetof)
# define offsetof(type, member) ((size_t)&((type *)0)->member)
#endif

#undef __need_size_t
#undef __need_ptrdiff_t
#undef __need_wchar_t
#undef __need_wint_t
#undef __need_NULL
#undef LBP_STDDEF_PARTIAL
