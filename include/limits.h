/* Project-authored limits.h for the PSP (psp-gcc 3.3.3 ABI: 8-bit char, signed by default; 16-bit short;
   32-bit int and long; 64-bit long long; two's complement). Written from ISO C 5.2.4.2.1; it contains no
   compiler vendor text. newlib's limits.h reaches it with #include_next and adds MB_LEN_MAX. */

#ifndef LBP_LIMITS_H
#define LBP_LIMITS_H

#define CHAR_BIT 8

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127
#define UCHAR_MAX 255

#define CHAR_MIN SCHAR_MIN
#define CHAR_MAX SCHAR_MAX

#define SHRT_MIN (-32767 - 1)
#define SHRT_MAX 32767
#define USHRT_MAX 65535

#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 4294967295U

#define LONG_MIN (-2147483647L - 1L)
#define LONG_MAX 2147483647L
#define ULONG_MAX 4294967295UL

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
# define LLONG_MIN (-9223372036854775807LL - 1LL)
# define LLONG_MAX 9223372036854775807LL
# define ULLONG_MAX 18446744073709551615ULL
#endif

#ifndef __STRICT_ANSI__
# define LONG_LONG_MIN (-9223372036854775807LL - 1LL)
# define LONG_LONG_MAX 9223372036854775807LL
# define ULONG_LONG_MAX 18446744073709551615ULL
#endif

#endif
