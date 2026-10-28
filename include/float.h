/* Project-authored float.h for the PSP (psp-gcc 3.3.3: IEEE 754 binary32 float, binary64 double, and
   long double the same as double). Written from ISO C 5.2.4.2.2 and the IEEE 754 formats; it contains no
   compiler vendor text. */

#ifndef LBP_FLOAT_H
#define LBP_FLOAT_H

#define FLT_RADIX 2
#define FLT_ROUNDS 1   /* round to nearest */

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
# define FLT_EVAL_METHOD 0
# define DECIMAL_DIG 17
#endif

/* float: binary32 */
#define FLT_MANT_DIG 24
#define FLT_DIG 6
#define FLT_MIN_EXP (-125)
#define FLT_MIN_10_EXP (-37)
#define FLT_MAX_EXP 128
#define FLT_MAX_10_EXP 38
#define FLT_MAX 3.40282347e+38F
#define FLT_EPSILON 1.19209290e-7F
#define FLT_MIN 1.17549435e-38F

/* double: binary64 */
#define DBL_MANT_DIG 53
#define DBL_DIG 15
#define DBL_MIN_EXP (-1021)
#define DBL_MIN_10_EXP (-307)
#define DBL_MAX_EXP 1024
#define DBL_MAX_10_EXP 308
#define DBL_MAX 1.7976931348623157e+308
#define DBL_EPSILON 2.2204460492503131e-16
#define DBL_MIN 2.2250738585072014e-308

/* long double: the same format as double */
#define LDBL_MANT_DIG DBL_MANT_DIG
#define LDBL_DIG DBL_DIG
#define LDBL_MIN_EXP DBL_MIN_EXP
#define LDBL_MIN_10_EXP DBL_MIN_10_EXP
#define LDBL_MAX_EXP DBL_MAX_EXP
#define LDBL_MAX_10_EXP DBL_MAX_10_EXP
#define LDBL_MAX 1.7976931348623157e+308L
#define LDBL_EPSILON 2.2204460492503131e-16L
#define LDBL_MIN 2.2250738585072014e-308L

#endif
