/* LBPMATCH module=EBOOT.BIN start=0x08ba85b8 end=0x08ba861c symbol=__mcmp lang=c99 cc=gcc402t-O2 */
/* Library source: newlib 1.14.0 libc_stdlib/mprec.c function __mcmp, preprocessed (comments kept), identified by compiled-code signature (lbplib.py) and built with the GCC profile in the header; exact match verified; external names are newlib's, their addresses read from retail. */
/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

/* Please send bug reports to
	David M. Gay
	AT&T Bell Laboratories, Room 2C-463
	600 Mountain Avenue
	Murray Hill, NJ 07974-2070
	U.S.A.
	dmg@research.att.com or research!dmg
 */

/* strtod for IEEE-, VAX-, and IBM-arithmetic machines.
 *
 * This strtod returns a nearest machine number to the input decimal
 * string (or sets errno to ERANGE).  With IEEE arithmetic, ties are
 * broken by the IEEE round-even rule.  Otherwise ties are broken by
 * biased rounding (add half and chop).
 *
 * Inspired loosely by William D. Clinger's paper "How to Read Floating
 * Point Numbers Accurately" [Proc. ACM SIGPLAN '90, pp. 92-101].
 *
 * Modifications:
 *
 *	1. We only require IEEE, IBM, or VAX double-precision
 *		arithmetic (not IEEE double-extended).
 *	2. We get by with floating-point arithmetic in a case that
 *		Clinger missed -- when we're computing d * 10^n
 *		for a small integer d and the integer n is not too
 *		much larger than 22 (the maximum integer k for which
 *		we can represent 10^k exactly), we may be able to
 *		compute (d*10^k) * 10^(e-k) with just one roundoff.
 *	3. Rather than a bit-at-a-time adjustment of the binary
 *		result in the hard case, we use floating-point
 *		arithmetic to determine the adjustment to within
 *		one bit; only in really hard cases do we need to
 *		compute a second residual.
 *	4. Because of 3., we don't need a large table of powers of 10
 *		for ten-to-e (just some small tables, e.g. of 10^k
 *		for 0 <= k <= 22).
 */

/*
 * #define IEEE_8087 for IEEE-arithmetic machines where the least
 *	significant byte has the lowest address.
 * #define IEEE_MC68k for IEEE-arithmetic machines where the most
 *	significant byte has the lowest address.
 * #define Sudden_Underflow for IEEE-format machines without gradual
 *	underflow (i.e., that flush to zero on underflow).
 * #define IBM for IBM mainframe-style floating-point arithmetic.
 * #define VAX for VAX-style floating-point arithmetic.
 * #define Unsigned_Shifts if >> does treats its left operand as unsigned.
 * #define No_leftright to omit left-right logic in fast floating-point
 *	computation of dtoa.
 * #define Check_FLT_ROUNDS if FLT_ROUNDS can assume the values 2 or 3.
 * #define RND_PRODQUOT to use rnd_prod and rnd_quot (assembly routines
 *	that use extended-precision instructions to compute rounded
 *	products and quotients) with IBM.
 * #define ROUND_BIASED for IEEE-format with biased rounding.
 * #define Inaccurate_Divide for IEEE-format with correctly rounded
 *	products but inaccurate quotients, e.g., for Intel i860.
 * #define Just_16 to store 16 bits per 32-bit long when doing high-precision
 *	integer arithmetic.  Whether this speeds things up or slows things
 *	down depends on the machine and the number being converted.
 */


/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* This file can define macros to choose variations of the IEEE float
   format:

   _FLT_LARGEST_EXPONENT_IS_NORMAL

	Defined if the float format uses the largest exponent for finite
	numbers rather than NaN and infinity representations.  Such a
	format cannot represent NaNs or infinities at all, but it's FLT_MAX
	is twice the IEEE value.

   _FLT_NO_DENORMALS

	Defined if the float format does not support IEEE denormals.  Every
	float with a zero exponent is taken to be a zero representation.
 
   ??? At the moment, there are no equivalent macros above for doubles and
   the macros are not fully supported by --enable-newlib-hw-fp.

   __IEEE_BIG_ENDIAN

        Defined if the float format is big endian.  This is mutually exclusive
        with __IEEE_LITTLE_ENDIAN.

   __IEEE_LITTLE_ENDIAN
 
        Defined if the float format is little endian.  This is mutually exclusive
        with __IEEE_BIG_ENDIAN.

   Note that one of __IEEE_BIG_ENDIAN or __IEEE_LITTLE_ENDIAN must be specified for a
   platform or error will occur.

   __IEEE_BYTES_LITTLE_ENDIAN

        This flag is used in conjunction with __IEEE_BIG_ENDIAN to describe a situation 
	whereby multiple words of an IEEE floating point are in big endian order, but the
	words themselves are little endian with respect to the bytes.

   _DOUBLE_IS_32_BITS 

        This is used on platforms that support double by using the 32-bit IEEE
        float type.

   _FLOAT_ARG

        This represents what type a float arg is passed as.  It is used when the type is
        not promoted to double.
	
*/
/* necv70 was __IEEE_LITTLE_ENDIAN. */
/* exceptions first */







/* 16 bit integer machines */
/* For the PowerPC eabi, force the _impure_ptr to be in .sdata */
/* This block should be kept in sync with GCC's limits.h.  The point
   of having these definitions here is to not include limits.h, which
   would pollute the user namespace, while still using types of the
   the correct widths when deciding how to define __int32_t and
   __int64_t.  */
/* End of block that should be kept in sync with GCC's limits.h.  */
/* Define return type of read/write routines.  In POSIX, the return type
   for read()/write() is "ssize_t" but legacy newlib code has been using
   "int" for some time.  If not specified, "int" is defaulted.  */
/* First try to figure out whether we really are in an ANSI C environment.  */
/* FIXME: This probably needs some work.  Perhaps sys/config.h can be
   prevailed upon to give us a clue.  */
/* Support gcc's __attribute__ facility.  */







/*  ISO C++.  */
/*
 * stdlib.h
 *
 * Definitions for common types, variables, and functions.
 */





/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* Project-authored stddef.h for the 32-bit little-endian PSP (Allegrex; ILP32 ABI of psp-gcc 3.3.3).
   Written from ISO C 7.17 and the type widths of that ABI. It contains no compiler vendor text.
   A header that needs only some of the types defines __need_size_t, __need_ptrdiff_t, __need_wchar_t,
   __need_wint_t or __need_NULL before including this file (the convention newlib's headers use);
   an include without any of them defines the full ISO set. */
typedef unsigned int size_t;
typedef int wchar_t;
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/
/* dummy lock routines for single-threaded aps */

typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
typedef long _off_t;
__extension__ typedef long long _off64_t;


typedef int _ssize_t;
typedef unsigned int wint_t;
/* Conversion state information.  */
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value; /* Value so far.  */
} _mbstate_t;

typedef _LOCK_RECURSIVE_T _flock_t;

/* Iconv descriptor type */
typedef void *_iconv_t;






typedef unsigned long __ULong;
/*
 * If _REENT_SMALL is defined, we make struct _reent as small as possible,
 * by having nearly everything possible allocated at first use.
 */

struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

/* needed by reentrant structure */
struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};

/*
 * atexit() support.
 */



struct _on_exit_args {
        void * _fnargs[32]; /* user fn args */
        void * _dso_handle[32];
        /* Bitmask is set if user function takes arguments.  */
        __ULong _fntypes; /* type of exit routine -
				   Must have at least _ATEXIT_SIZE bits */
        /* Bitmask is set if function was registered via __cxa_atexit.  */
        __ULong _is_cxa;
};
struct _atexit {
        struct _atexit *_next; /* next in list */
        int _ind; /* next index in this table */
        /* Some entries may already have been called, and will be NULL.  */
        void (*_fns[32])(void); /* the table itself */
        struct _on_exit_args _on_exit_args;
};


/*
 * Stdio buffers.
 *
 * This and __FILE are defined here because we need them for struct _reent,
 * but we don't want stdio.h included when stdlib.h is.
 */

struct __sbuf {
        unsigned char *_base;
        int _size;
};

/*
 * We need fpos_t for the following, but it doesn't have a leading "_",
 * so we use _fpos_t instead.
 */

typedef long _fpos_t; /* XXX must match off_t in <sys/types.h> */
                                /* (and must be `long' for now) */





/*
 * Stdio state variables.
 *
 * The following always hold:
 *
 *	if (_flags&(__SLBF|__SWR)) == (__SLBF|__SWR),
 *		_lbfsize is -_bf._size, else _lbfsize is 0
 *	if _flags&__SRD, _w is 0
 *	if _flags&__SWR, _r is 0
 *
 * This ensures that the getc and putc macros (or inline functions) never
 * try to write or read from a file that is in `read' or `write' mode.
 * (Moreover, they can, and do, automatically switch from read mode to
 * write mode, and back, on "r+" and "w+" files.)
 *
 * _lbfsize is used only to make the inline line-buffered output stream
 * code as compact as possible.
 *
 * _ub, _up, and _ur are used when ungetc() pushes back more characters
 * than fit in the current _bf, or when ungetc() pushes back a character
 * that does not match the previous one in _bf.  When this happens,
 * _ub._base becomes non-nil (i.e., a stream has ungetc() data iff
 * _ub._base!=NULL) and _up and _ur save the current values of _p and _r.
 */
struct __sFILE {
  unsigned char *_p; /* current position in (some) buffer */
  int _r; /* read space left for getc() */
  int _w; /* write space left for putc() */
  short _flags; /* flags, below; this FILE is free if 0 */
  short _file; /* fileno, if Unix descriptor, else -1 */
  struct __sbuf _bf; /* the buffer (at least 1 byte, if !NULL) */
  int _lbfsize; /* 0 or -_bf._size, for inline putc */





  /* operations */
  void * _cookie; /* cookie passed to io functions */

  int (*_read) (void * _cookie, char *_buf, int _n);
  int (*_write) (void * _cookie, const char *_buf, int _n);

  _fpos_t (*_seek) (void * _cookie, _fpos_t _offset, int _whence);
  int (*_close) (void * _cookie);

  /* separate buffer for long sequences of ungetc() */
  struct __sbuf _ub; /* ungetc buffer */
  unsigned char *_up; /* saved _p when _p is doing ungetc data */
  int _ur; /* saved _r when _r is counting ungetc data */

  /* tricks to meet minimum requirements even when malloc() fails */
  unsigned char _ubuf[3]; /* guarantee an ungetc() buffer */
  unsigned char _nbuf[1]; /* guarantee a getc() buffer */

  /* separate buffer for fgetline() when line crosses buffer boundary */
  struct __sbuf _lb; /* buffer for fgetline() */

  /* Unix stdio files get aligned to block boundaries on fseek() */
  int _blksize; /* stat.st_blksize (may be != _bf._size) */
  int _offset; /* current lseek offset */


  struct _reent *_data; /* Here for binary compatibility? Remove? */



  _flock_t _lock; /* for thread-safety locking */

};
typedef struct __sFILE __FILE;


struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};

/*
 * rand48 family support
 *
 * Copyright (c) 1993 Martin Birgmeier
 * All rights reserved.
 *
 * You may redistribute unmodified or modified versions of this source
 * code provided that the above copyright notice and this and the
 * following conditions are retained.
 *
 * This software is provided ``as is'', and comes with no warranties
 * of any kind. I shall in no event be liable for anything that happens
 * to anyone/anything when using this software.
 */







struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};

/* How big the some arrays are.  */




/*
 * struct _reent
 *
 * This structure contains *all* globals needed by the library.
 * It's raison d'etre is to facilitate threads by making all library routines
 * reentrant.  IE: All state information is contained here.
 */
struct _reent
{
  int _errno; /* local copy of errno */

  /* FILE is a big struct and may change over time.  To try to achieve binary
     compatibility with future versions, put stdin,stdout,stderr here.
     These are pointers into member __sf defined below.  */
  __FILE *_stdin, *_stdout, *_stderr;

  int _inc; /* used by tmpnam */
  char _emergency[25];

  int _current_category; /* used by setlocale */
  const char *_current_locale;

  int __sdidinit; /* 1 means stdio has been init'd */

  void (*__cleanup) (struct _reent *);

  /* used by mprec routines */
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;

  /* used by some fp conversion routines */
  int _cvtlen; /* should be size_t */
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
        } _reent;
  /* Two next two fields were once used by malloc.  They are no longer
     used. They are used to preserve the space used before so as to
     allow addition of new reent fields and keep binary compatibility.   */
      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;

  /* atexit stuff */
  struct _atexit *_atexit; /* points to head of LIFO stack */
  struct _atexit _atexit0; /* one guaranteed table, required by ANSI */

  /* signal info */
  void (**(_sig_func))(int);

  /* These are here last so that __FILE can grow without changing the offsets
     of the above members (on the off chance that future binary compatibility
     would be broken otherwise).  */
  struct _glue __sglue; /* root of glue chain */
  __FILE __sf[3]; /* first three file descriptors */
};
/*
 * All references to struct _reent are via this pointer.
 * Internally, newlib routines that need to reference it should use _REENT.
 */





extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);

/* #define _REENT_ONLY define this to get only reentrant routines */
/* place holder so platforms may add stdlib.h extensions */






/* libc/include/alloca.h - Allocate memory on stack */

/* Written 2000 by Werner Almesberger */
/* Rearranged for general inclusion by stdlib.h.
   2001, Corinna Vinschen <vinschen@redhat.com> */





/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */


typedef struct
{
  int quot; /* quotient */
  int rem; /* remainder */
} div_t;

typedef struct
{
  long quot; /* quotient */
  long rem; /* remainder */
} ldiv_t;


typedef struct
{
  long long int quot; /* quotient */
  long long int rem; /* remainder */
} lldiv_t;
extern int __mb_cur_max;



void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);

float atoff (const char *__nptr);

int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, int (* _compar) (const void *, const void *));




void * calloc (size_t __nmemb, size_t __size);
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *);
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size);
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, _mbstate_t *);


int mkstemp (char *);
char * mktemp (char *);


void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size);
void srand (unsigned __seed);
double strtod (const char *__n, char **__end_PTR);
double _strtod_r (struct _reent *,const char *__n, char **__end_PTR);
float strtof (const char *__n, char **__end_PTR);

/* the following strtodf interface is deprecated...use strtof instead */




long strtol (const char *__n, char **__end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__n, char **__end_PTR, int __base);
unsigned long strtoul (const char *__n, char **__end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__n, char **__end_PTR, int __base);

int system (const char *__string);


long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (char *__string);
int _putenv_r (struct _reent *, char *__string);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);

char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);

double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long atoll (const char *__nptr);
long long _atoll_r (struct _reent *, const char *__nptr);
long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *__n, char **__end_PTR, int __base);
long long _strtoll_r (struct _reent *, const char *__n, char **__end_PTR, int __base);
unsigned long long strtoull (const char *__n, char **__end_PTR, int __base);
unsigned long long _strtoull_r (struct _reent *, const char *__n, char **__end_PTR, int __base);


void cfree (void *);
void unsetenv (const char *__string);
void _unsetenv_r (struct _reent *, const char *__string);




char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t);
void * _calloc_r (struct _reent *, size_t, size_t);
void _free_r (struct _reent *, void *);
void * _realloc_r (struct _reent *, void *, size_t);
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);





/*
 * string.h
 *
 * Definitions for memory and string functions.
 */





/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *, const void *, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);


char *strtok (char *, const char *);


size_t strxfrm (char *, const char *, size_t);


char *strtok_r (char *, const char *, char **);

int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void *, const void *, int, size_t);
void * mempcpy (void *, const void *, size_t);



char *rindex (const char *, int);
int strcasecmp (const char *, const char *);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
char *strndup (const char *, size_t);
char *_strndup_r (struct _reent *, const char *, size_t);
char *strerror_r (int, char *, size_t);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
int strncasecmp (const char *, const char *, size_t);
size_t strnlen (const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);







/* These function names are used on Windows and perhaps other systems.  */
/* This is a dummy <sys/string.h> used as a placeholder for
   systems that need to have a special header file.  */





/* This header file provides the reentrancy.  */

/* The reentrant system calls here serve two purposes:

   1) Provide reentrant versions of the system calls the ANSI C library
      requires.
   2) Provide these system calls in a namespace clean way.

   It is intended that *all* system calls that the ANSI C library needs
   be declared here.  It documents them all in one place.  All library access
   to the system is via some form of these functions.

   There are three ways a target may provide the needed syscalls.

   1) Define the reentrant versions of the syscalls directly.
      (eg: _open_r, _close_r, etc.).  Please keep the namespace clean.
      When you do this, set "syscall_dir" to "syscalls" and add
      -DREENTRANT_SYSCALLS_PROVIDED to newlib_cflags in configure.host.

   2) Define namespace clean versions of the system calls by prefixing
      them with '_' (eg: _open, _close, etc.).  Technically, there won't be
      true reentrancy at the syscall level, but the library will be namespace
      clean.
      When you do this, set "syscall_dir" to "syscalls" in configure.host.

   3) Define or otherwise provide the regular versions of the syscalls
      (eg: open, close, etc.).  The library won't be reentrant nor namespace
      clean, but at least it will work.
      When you do this, add -DMISSING_SYSCALL_NAMES to newlib_cflags in
      configure.host.

   Stubs of the reentrant versions of the syscalls exist in the libc/reent
   source directory and are used if REENTRANT_SYSCALLS_PROVIDED isn't defined.
   They use the native system calls: _open, _close, etc. if they're available
   (MISSING_SYSCALL_NAMES is *not* defined), otherwise open, close, etc.
   (MISSING_SYSCALL_NAMES *is* defined).  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/
/*
 *  The following section is RTEMS specific and is needed to more
 *  closely match the types defined in the BSD machine/types.h.
 *  This is needed to let the RTEMS/BSD TCP/IP stack compile.
 */
typedef long int __off_t;
typedef int __pid_t;

__extension__ typedef long long int __loff_t;
typedef int ptrdiff_t;
/* FIXME: not namespace clean */
struct stat;
struct tms;
struct timeval;
struct timezone;

/* Reentrant versions of system calls.  */

extern int _close_r (struct _reent *, int);
extern int _execve_r (struct _reent *, char *, char **, char **);
extern int _fcntl_r (struct _reent *, int, int, int);
extern int _fork_r (struct _reent *);
extern int _fstat_r (struct _reent *, int, struct stat *);
extern int _getpid_r (struct _reent *);
extern int _kill_r (struct _reent *, int, int);
extern int _link_r (struct _reent *, const char *, const char *);
extern _off_t _lseek_r (struct _reent *, int, _off_t, int);
extern int _open_r (struct _reent *, const char *, int, int);
extern _ssize_t _read_r (struct _reent *, int, void *, size_t);
extern void *_sbrk_r (struct _reent *, ptrdiff_t);
extern int _stat_r (struct _reent *, const char *, struct stat *);
extern unsigned long _times_r (struct _reent *, struct tms *);
extern int _unlink_r (struct _reent *, const char *);
extern int _wait_r (struct _reent *, int *);
extern _ssize_t _write_r (struct _reent *, int, const void *, size_t);

/* This one is not guaranteed to be available on all targets.  */
extern int _gettimeofday_r (struct _reent *, struct timeval *tp, struct timezone *tzp);
/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

/* Please send bug reports to
	David M. Gay
	AT&T Bell Laboratories, Room 2C-463
	600 Mountain Avenue
	Murray Hill, NJ 07974-2070
	U.S.A.
	dmg@research.att.com or research!dmg
 */






/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */


/* FIXME FIXME FIXME:
   Neither of __ieee_{float,double}_shape_tape seem to be used anywhere
   except in libm/test.  If that is the case, please delete these from here.
   If that is not the case, please insert documentation here describing why
   they're needed.  */
typedef union
{
  double value;
  struct
  {






    unsigned int fraction1:32;
    unsigned int fraction0:20;

    unsigned int exponent :11;
    unsigned int sign : 1;
  } number;
  struct
  {






    unsigned int function1:32;
    unsigned int function0:19;

    unsigned int quiet:1;
    unsigned int exponent: 11;
    unsigned int sign : 1;
  } nan;
  struct
  {
    unsigned long lsw;
    unsigned long msw;
  } parts;

  long aslong[2];

} __ieee_double_shape_type;
typedef union
{
  float value;
  struct
  {
    unsigned int fraction0: 7;
    unsigned int fraction1: 16;
    unsigned int exponent: 8;
    unsigned int sign : 1;
  } number;
  struct
  {
    unsigned int function1:16;
    unsigned int function0:6;
    unsigned int quiet:1;
    unsigned int exponent:8;
    unsigned int sign:1;
  } nan;
  long p1;

} __ieee_float_shape_type;







/* FLOATING ROUNDING */

typedef int fp_rnd;





fp_rnd fpgetround (void);
fp_rnd fpsetround (fp_rnd);

/* EXCEPTIONS */

typedef int fp_except;






fp_except fpgetmask (void);
fp_except fpsetmask (fp_except);
fp_except fpgetsticky (void);
fp_except fpsetsticky (fp_except);

/* INTEGER ROUNDING */

typedef int fp_rdi;



fp_rdi fpgetroundtoi (void);
fp_rdi fpsetroundtoi (fp_rdi);

int isnan (double);
int isinf (double);
int finite (double);



int isnanf (float);
int isinff (float);
int finitef (float);




/* math.h -- Definitions for the math floating point package.  */





/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */


union __dmath
{
  __ULong i[2];
  double d;
};

union __fmath
{
  __ULong i[1];
  float f;
};

union __ldmath
{
  __ULong i[4];
  long double ld;
};





 /* gcc >= 3.3 implicitly defines builtins for HUGE_VALx values.  */
/* Reentrant ANSI C functions.  */


extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);


/* Non reentrant ANSI C functions.  */



extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);





/* ISO C99 types and macros. */



typedef float float_t;
typedef double double_t;
extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);
/* Non ANSI double precision functions.  */

extern double infinity (void);
extern double nan (const char *);
extern int isnan (double);
extern int isinf (double);
extern int finite (double);
extern double copysign (double, double);
extern int ilogb (double);

extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);

extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern double round (double);
extern long int lround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double copysign (double, double);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);
extern void sincos (double, double *, double *);


extern double log1p (double);
extern double expm1 (double);



extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double gamma_r (double, int *);
extern double lgamma (double);
extern double lgamma_r (double, int *);
extern double erf (double);
extern double erfc (double);
extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);



extern double hypot (double, double);


extern double cabs();
extern double drem (double, double);







/* Single precision versions of ANSI functions.  */

extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);


extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);






/* Other single precision functions.  */

extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float copysignf (float, float);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);

extern float infinityf (void);
extern float nanf (const char *);
extern int isnanf (float);
extern int isinff (float);
extern int finitef (float);
extern float copysignf (float, float);
extern int ilogbf (float);

extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);
extern void sincosf (float, float *, float *);


extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float gammaf_r (float, int *);
extern float lgammaf (float);
extern float lgammaf_r (float, int *);
extern float erff (float);
extern float erfcf (float);
extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);

extern float hypotf (float, float);

extern float cabsf();
extern float dremf (float, float);



/* The gamma functions use a global variable, signgam.  */


extern int *__signgam (void);




/* The exception structure passed to the matherr routine.  */




struct exception

{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};




extern int matherr (struct exception *e);


/* Values for the type field of struct exception.  */
/* Useful constants.  */
/* Global control over fdlibm error handling.  */

enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};




extern const enum __fdlibm_version __fdlib_version;








/* Project-authored float.h for the PSP (psp-gcc 3.3.3: IEEE 754 binary32 float, binary64 double, and
   long double the same as double). Written from ISO C 5.2.4.2.2 and the IEEE 754 formats; it contains no
   compiler vendor text. */
/* float: binary32 */
/* double: binary64 */
/* long double: the same format as double */
typedef int error_t;




/* errno is not a global variable, because that would make using it
   non-reentrant.  Instead, its address is returned by the function
   __errno.  */
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
extern int *__errno (void);


/* Please don't use these variables directly.
   Use strerror instead. */
extern const char * const _sys_errlist[];
extern int _sys_nerr;
/* From cygwin32.  */
/* unified sys/types.h: 
   start with sef's sysvi386 version.
   merge go32 version -- a few ifdefs.
   h8300hms, h8300xray, and sysvnecv70 disagree on the following types:

   typedef int gid_t;
   typedef int uid_t;
   typedef int dev_t;
   typedef int ino_t;
   typedef int mode_t;
   typedef int caddr_t;

   however, these aren't "reasonable" values, the sysvi386 ones make far 
   more sense, and should work sufficiently well (in particular, h8300 
   doesn't have a stat, and the necv70 doesn't matter.) -- eichin
 */




/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/*
 *  $Id: _types.h,v 1.2 2005/03/22 18:12:29 cgf Exp $
 */
/*
 * Guess on types by examining *_MIN / *_MAX defines.
 */


/* GCC >= 3.3.0 has __<val>__ implicitly defined. */
typedef signed char __int8_t ;
typedef unsigned char __uint8_t ;
typedef signed short __int16_t;
typedef unsigned short __uint16_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef signed long long __int64_t;
typedef unsigned long long __uint64_t;


/* POSIX mandates LLONG_MAX in <limits.h> */
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/
/* To ensure the stat struct's layout doesn't change when sizeof(int), etc.
   changes, we assume sizeof short and long never change and have all types
   used to define struct stat use them and not int where possible.
   Where not possible, _ST_INTxx are used.  It would be preferable to not have
   such assumptions, but until the extra fluff is necessary, it's avoided.
   No 64 bit targets use stat yet.  What to do about them is postponed
   until necessary.  */
/* also defined in mingw/gmon.h and in w32api/winsock[2].h */
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;



typedef unsigned short ushort; /* System V compatibility */
typedef unsigned int uint; /* System V compatibility */



typedef unsigned long clock_t;




typedef long time_t;


/* Time Value Specification Structures, P1003.1b-1993, p. 261 */

struct timespec {
  time_t tv_sec; /* Seconds */
  long tv_nsec; /* Nanoseconds */
};

struct itimerspec {
  struct timespec it_interval; /* Timer period */
  struct timespec it_value; /* Timer expiration */
};


typedef long daddr_t;
typedef char * caddr_t;
typedef unsigned short ino_t;
/*
 * All these should be machine specific - right now they are all broken.
 * However, for all of Cygnus' embedded targets, we want them to all be
 * the same.  Otherwise things like sizeof (struct stat) might depend on
 * how the file was compiled (e.g. -mint16 vs -mint32, etc.).
 */






typedef short dev_t;




typedef long off_t;

typedef unsigned short uid_t;
typedef unsigned short gid_t;


typedef int pid_t;

typedef long key_t;

typedef _ssize_t ssize_t;
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));




typedef unsigned short nlink_t;

/* We don't define fd_set and friends if we are compiling POSIX
   source, or if we have included (or may include as indicated
   by __USE_W32_SOCKETS) the W32api winsock[2].h header which
   defines Windows versions of them.   Note that a program which
   includes the W32api winsock[2].h header must know what it is doing;
   it must not call the cygwin32 select function.
*/



/*
 * Select uses bit masks of file descriptors in longs.
 * These macros manipulate such bit fields (the filesystem macros use chars).
 * FD_SETSIZE may be defined by the user, but the default here
 * should be >= NOFILE (param.h).
 */




typedef long fd_mask;





/* We use a macro for fd_set so that including Sockets.h afterwards
   can work.  */
typedef struct _types_fd_set {
        fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;
typedef unsigned long clockid_t;




typedef unsigned long timer_t;



typedef long useconds_t;


/*
 *  Written by Joel Sherrill <joel@OARcorp.com>.
 *
 *  COPYRIGHT (c) 1989-2000.
 *
 *  On-Line Applications Research Corporation (OAR).
 *
 *  Permission to use, copy, modify, and distribute this software for any
 *  purpose without fee is hereby granted, provided that this entire notice
 *  is included in all copies of any software which is or includes a copy
 *  or modification of this software.
 *
 *  THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 *  WARRANTY.  IN PARTICULAR,  THE AUTHOR MAKES NO REPRESENTATION
 *  OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY OF THIS
 *  SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 *  $Id: features.h,v 1.7 2005/10/18 18:39:46 corinna Exp $
 */
/* RTEMS adheres to POSIX -- 1003.1b with some features from annexes.  */
/* Cygwin will probably never have full posix compliance due to little things
 * like an inability to set the stackaddress. Cygwin is also using void *  
 * pointers rather than structs to ensure maximum binary compatability with
 * previous releases.
 * This means that we don't use the types defined here, but rather in
 * <cygwin/types.h>
 */
/* If we are going to examine or modify specific bits in a double using
   the word0 and/or word1 macros, then we must wrap the double inside
   a union.  This is necessary to avoid undefined behavior according to
   the ANSI C spec.  */
union double_union
{
  double d;
  __uint32_t i[2];
};
/* The following definition of Storeinc is appropriate for MIPS processors.
 * An alternative that might be better on some machines is
 * #define Storeinc(a,b,c) (*a++ = b << 16 | c & 0xffff)
 */
/* #define P DBL_MANT_DIG */
/* Ten_pmax = floor(P*log(2)/log(5)) */
/* Bletch = (highest power of 2 < DBL_MAX_10_EXP) / 16 */
/* Quick_max = floor((P-1)*log(FLT_RADIX)/log(10) - 1) */
/* Int_max = floor(P*log(FLT_RADIX)/log(10) - 1) */
/* When Pack_32 is not defined, we store 16 bits per 32-bit long.
 * This makes some inner loops simpler and sometimes saves work
 * during multiplications, but it often seems to make things slightly
 * slower.  Hence the default is now to store 32 bits per long.
 */
typedef struct _Bigint _Bigint;
struct _reent ;
double _ulp (double x);
double _b2d (_Bigint *a , int *e);
_Bigint * _Balloc (struct _reent *p, int k);
void _Bfree (struct _reent *p, _Bigint *v);
_Bigint * _multadd (struct _reent *p, _Bigint *, int, int);
_Bigint * _s2b (struct _reent *, const char*, int, int, __ULong);
_Bigint * _i2b (struct _reent *,int);
_Bigint * _multiply (struct _reent *, _Bigint *, _Bigint *);
_Bigint * _pow5mult (struct _reent *, _Bigint *, int k);
int _hi0bits (__ULong);
int _lo0bits (__ULong *);
_Bigint * _d2b (struct _reent *p, double d, int *e, int *bits);
_Bigint * _lshift (struct _reent *p, _Bigint *b, int k);
_Bigint * __mdiff (struct _reent *p, _Bigint *a, _Bigint *b);
int __mcmp (_Bigint *a, _Bigint *b);

double _ratio (_Bigint *a, _Bigint *b);
extern const double __mprec_tinytens[];
extern const double __mprec_bigtens[];
extern const double __mprec_tens[];


double _mprec_log10 (int);

/* reent.c knows this value */


_Bigint *
_Balloc(struct _reent *ptr , int k)
{
  int x;
  _Bigint *rv ;

  ;
  if (((ptr)->_freelist) == ((void *)0))
    {
      /* Allocate a list of pointers to the mprec objects */
      ((ptr)->_freelist) = (struct _Bigint **) _calloc_r (ptr,
                                                      sizeof (struct _Bigint *),
                                                      15 + 1);
      if (((ptr)->_freelist) == ((void *)0))
        {
          return ((void *)0);
        }
    }

  if ((rv = ((ptr)->_freelist)[k]) != 0)
    {
      ((ptr)->_freelist)[k] = rv->_next;
    }
  else
    {
      x = 1 << k;
      /* Allocate an mprec Bigint and stick in in the freelist */
      rv = (_Bigint *) _calloc_r (ptr,
                                  1,
                                  sizeof (_Bigint) +
                                  (x-1) * sizeof(rv->_x));
      if (rv == ((void *)0)) return ((void *)0);
      rv->_k = k;
      rv->_maxwds = x;
    }
  rv->_sign = rv->_wds = 0;
  return rv;
}

void
_Bfree(struct _reent *ptr , _Bigint * v)
{
  ;
  if (v)
    {
      v->_next = ((ptr)->_freelist)[v->_k];
      ((ptr)->_freelist)[v->_k] = v;
    }
}

_Bigint *
_multadd(struct _reent *ptr , _Bigint * b , int m , int a)




{
  int i, wds;
  __ULong *x, y;

  __ULong xi, z;

  _Bigint *b1;

  wds = b->_wds;
  x = b->_x;
  i = 0;
  do
    {

      xi = *x;
      y = (xi & 0xffff) * m + a;
      z = (xi >> 16) * m + (y >> 16);
      a = (int) (z >> 16);
      *x++ = (z << 16) + (y & 0xffff);





    }
  while (++i < wds);
  if (a)
    {
      if (wds >= b->_maxwds)
        {
          b1 = _Balloc (ptr, b->_k + 1);
          memcpy((char *)&b1->_sign, (char *)&b->_sign, b->_wds*sizeof(long) + 2*sizeof(int));
          _Bfree (ptr, b);
          b = b1;
        }
      b->_x[wds++] = a;
      b->_wds = wds;
    }
  return b;
}

_Bigint *
_s2b(struct _reent * ptr , const char *s , int nd0 , int nd , __ULong y9)





{
  _Bigint *b;
  int i, k;
  long x, y;

  x = (nd + 8) / 9;
  for (k = 0, y = 1; x > y; y <<= 1, k++);

  b = _Balloc (ptr, k);
  b->_x[0] = y9;
  b->_wds = 1;






  i = 9;
  if (9 < nd0)
    {
      s += 9;
      do
        b = _multadd (ptr, b, 10, *s++ - '0');
      while (++i < nd0);
      s++;
    }
  else
    s += 10;
  for (; i < nd; i++)
    b = _multadd (ptr, b, 10, *s++ - '0');
  return b;
}

int
_hi0bits(register __ULong x)

{
  register int k = 0;

  if (!(x & 0xffff0000))
    {
      k = 16;
      x <<= 16;
    }
  if (!(x & 0xff000000))
    {
      k += 8;
      x <<= 8;
    }
  if (!(x & 0xf0000000))
    {
      k += 4;
      x <<= 4;
    }
  if (!(x & 0xc0000000))
    {
      k += 2;
      x <<= 2;
    }
  if (!(x & 0x80000000))
    {
      k++;
      if (!(x & 0x40000000))
        return 32;
    }
  return k;
}

int
_lo0bits(__ULong *y)
{
  register int k;
  register __ULong x = *y;

  if (x & 7)
    {
      if (x & 1)
        return 0;
      if (x & 2)
        {
          *y = x >> 1;
          return 1;
        }
      *y = x >> 2;
      return 2;
    }
  k = 0;
  if (!(x & 0xffff))
    {
      k = 16;
      x >>= 16;
    }
  if (!(x & 0xff))
    {
      k += 8;
      x >>= 8;
    }
  if (!(x & 0xf))
    {
      k += 4;
      x >>= 4;
    }
  if (!(x & 0x3))
    {
      k += 2;
      x >>= 2;
    }
  if (!(x & 1))
    {
      k++;
      x >>= 1;
      if (!x & 1)
        return 32;
    }
  *y = x;
  return k;
}

_Bigint *
_i2b(struct _reent * ptr , int i)
{
  _Bigint *b;

  b = _Balloc (ptr, 1);
  b->_x[0] = i;
  b->_wds = 1;
  return b;
}

_Bigint *
_multiply(struct _reent * ptr , _Bigint * a , _Bigint * b)
{
  _Bigint *c;
  int k, wa, wb, wc;
  __ULong carry, y, z;
  __ULong *x, *xa, *xae, *xb, *xbe, *xc, *xc0;

  __ULong z2;


  if (a->_wds < b->_wds)
    {
      c = a;
      a = b;
      b = c;
    }
  k = a->_k;
  wa = a->_wds;
  wb = b->_wds;
  wc = wa + wb;
  if (wc > a->_maxwds)
    k++;
  c = _Balloc (ptr, k);
  for (x = c->_x, xa = x + wc; x < xa; x++)
    *x = 0;
  xa = a->_x;
  xae = xa + wa;
  xb = b->_x;
  xbe = xb + wb;
  xc0 = c->_x;

  for (; xb < xbe; xb++, xc0++)
    {
      if ((y = *xb & 0xffff) != 0)
        {
          x = xa;
          xc = xc0;
          carry = 0;
          do
            {
              z = (*x & 0xffff) * y + (*xc & 0xffff) + carry;
              carry = z >> 16;
              z2 = (*x++ >> 16) * y + (*xc >> 16) + carry;
              carry = z2 >> 16;
              (((unsigned short *)xc)[1] = (unsigned short)z2, ((unsigned short *)xc)[0] = (unsigned short)z, xc++);
            }
          while (x < xae);
          *xc = carry;
        }
      if ((y = *xb >> 16) != 0)
        {
          x = xa;
          xc = xc0;
          carry = 0;
          z2 = *xc;
          do
            {
              z = (*x & 0xffff) * y + (*xc >> 16) + carry;
              carry = z >> 16;
              (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)z2, xc++);
              z2 = (*x++ >> 16) * y + (*xc & 0xffff) + carry;
              carry = z2 >> 16;
            }
          while (x < xae);
          *xc = z2;
        }
    }
  for (xc0 = c->_x, xc = xc0 + wc; wc > 0 && !*--xc; --wc);
  c->_wds = wc;
  return c;
}

_Bigint *
_pow5mult(struct _reent * ptr , _Bigint * b , int k)

{
  _Bigint *b1, *p5, *p51;
  int i;
  static const int p05[3] = {5, 25, 125};

  if ((i = k & 3) != 0)
    b = _multadd (ptr, b, p05[i - 1], 0);

  if (!(k >>= 2))
    return b;
  ;
  if (!(p5 = ((ptr)->_p5s)))
    {
      /* first time */
      p5 = ((ptr)->_p5s) = _i2b (ptr, 625);
      p5->_next = 0;
    }
  for (;;)
    {
      if (k & 1)
        {
          b1 = _multiply (ptr, b, p5);
          _Bfree (ptr, b);
          b = b1;
        }
      if (!(k >>= 1))
        break;
      if (!(p51 = p5->_next))
        {
          p51 = p5->_next = _multiply (ptr, p5, p5);
          p51->_next = 0;
        }
      p5 = p51;
    }
  return b;
}

_Bigint *
_lshift(struct _reent * ptr , _Bigint * b , int k)
{
  int i, k1, n, n1;
  _Bigint *b1;
  __ULong *x, *x1, *xe, z;


  n = k >> 5;



  k1 = b->_k;
  n1 = n + b->_wds + 1;
  for (i = b->_maxwds; n1 > i; i <<= 1)
    k1++;
  b1 = _Balloc (ptr, k1);
  x1 = b1->_x;
  for (i = 0; i < n; i++)
    *x1++ = 0;
  x = b->_x;
  xe = x + b->_wds;

  if (k &= 0x1f)
    {
      k1 = 32 - k;
      z = 0;
      do
        {
          *x1++ = *x << k | z;
          z = *x++ >> k1;
        }
      while (x < xe);
      if ((*x1 = z) != 0)
        ++n1;
    }
  else
    do
      *x1++ = *x++;
    while (x < xe);
  b1->_wds = n1 - 1;
  _Bfree (ptr, b);
  return b1;
}

int
__mcmp(_Bigint * a , _Bigint * b)
{
  __ULong *xa, *xa0, *xb, *xb0;
  int i, j;

  i = a->_wds;
  j = b->_wds;






  if (i -= j)
    return i;
  xa0 = a->_x;
  xa = xa0 + j;
  xb0 = b->_x;
  xb = xb0 + j;
  for (;;)
    {
      if (*--xa != *--xb)
        return *xa < *xb ? -1 : 1;
      if (xa <= xa0)
        break;
    }
  return 0;
}

_Bigint *
__mdiff(struct _reent * ptr , _Bigint * a , _Bigint * b)

{
  _Bigint *c;
  int i, wa, wb;
  long borrow, y; /* We need signed shifts here. */
  __ULong *xa, *xae, *xb, *xbe, *xc;

  long z;


  i = __mcmp (a, b);
  if (!i)
    {
      c = _Balloc (ptr, 0);
      c->_wds = 1;
      c->_x[0] = 0;
      return c;
    }
  if (i < 0)
    {
      c = a;
      a = b;
      b = c;
      i = 1;
    }
  else
    i = 0;
  c = _Balloc (ptr, a->_k);
  c->_sign = i;
  wa = a->_wds;
  xa = a->_x;
  xae = xa + wa;
  wb = b->_wds;
  xb = b->_x;
  xbe = xb + wb;
  xc = c->_x;
  borrow = 0;

  do
    {
      y = (*xa & 0xffff) - (*xb & 0xffff) + borrow;
      borrow = y >> 16;
      ;
      z = (*xa++ >> 16) - (*xb++ >> 16) + borrow;
      borrow = z >> 16;
      ;
      (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)y, xc++);
    }
  while (xb < xbe);
  while (xa < xae)
    {
      y = (*xa & 0xffff) + borrow;
      borrow = y >> 16;
      ;
      z = (*xa++ >> 16) + borrow;
      borrow = z >> 16;
      ;
      (((unsigned short *)xc)[1] = (unsigned short)z, ((unsigned short *)xc)[0] = (unsigned short)y, xc++);
    }
  while (!*--xc)
    wa--;
  c->_wds = wa;
  return c;
}

double
_ulp(double _x)
{
  union double_union x, a;
  register long L;

  x.d = _x;

  L = ((x.i[1]) & ((__uint32_t)0x7ff00000L)) - (53 - 1) * ((__uint32_t)0x100000L);

  if (L > 0)
    {




      (a.i[1]) = L;

      (a.i[0]) = 0;



    }
  else
    {
      L = -L >> 20;
      if (L < 20)
        {
          (a.i[1]) = 0x80000 >> L;

          (a.i[0]) = 0;

        }
      else
        {
          (a.i[1]) = 0;
          L -= 20;

         (a.i[0]) = L >= 31 ? 1 : 1 << (31 - L);

        }
    }

  return a.d;
}

double
_b2d(_Bigint * a , int *e)

{
  __ULong *xa, *xa0, w, y, z;
  int k;
  union double_union d;







  xa0 = a->_x;
  xa = xa0 + a->_wds;
  y = *--xa;




  k = _hi0bits (y);
  *e = 32 - k;

  if (k < 11)
    {
      (d.i[1]) = ((__uint32_t)0x3ff00000L) | y >> (11 - k);
      w = xa > xa0 ? *--xa : 0;

      (d.i[0]) = y << ((32 - 11) + k) | w >> (11 - k);

      goto ret_d;
    }
  z = xa > xa0 ? *--xa : 0;
  if (k -= 11)
    {
      (d.i[1]) = ((__uint32_t)0x3ff00000L) | y << k | z >> (32 - k);
      y = xa > xa0 ? *--xa : 0;

      (d.i[0]) = z << k | y >> (32 - k);

    }
  else
    {
      (d.i[1]) = ((__uint32_t)0x3ff00000L) | y;

      (d.i[0]) = z;

    }
ret_d:







  return d.d;
}

_Bigint *
_d2b(struct _reent * ptr , double _d , int *e , int *bits)






{
  union double_union d;
  _Bigint *b;
  int de, i, k;
  __ULong *x, y, z;



  d.d = _d;






  d.d = _d;



  b = _Balloc (ptr, 1);



  x = b->_x;

  z = (d.i[1]) & ((__uint32_t)0xfffffL);
  (d.i[1]) &= 0x7fffffff; /* clear sign bit, which we ignore */






  if ((de = (int) ((d.i[1]) >> 20)) != 0)
    z |= ((__uint32_t)0x100000L);



  if ((d.i[0]))
    {
      y = (d.i[0]);
      k = _lo0bits (&y);
      if (k)
        {
         x[0] = y | z << (32 - k);
          z >>= k;
        }
      else
        x[0] = y;
      i = b->_wds = (x[1] = z) ? 2 : 1;
    }
  else

    {




      k = _lo0bits (&z);
      x[0] = z;
      i = b->_wds = 1;

      k += 32;

    }
  if (de)
    {





      *e = de - 1023 - (53 - 1) + k;
      *bits = 53 - k;


    }
  else
    {
      *e = de - 1023 - (53 - 1) + 1 + k;

      *bits = 32 * i - _hi0bits (x[i - 1]);



    }

  return b;
}



double
_ratio(_Bigint * a , _Bigint * b)

{
  union double_union da, db;
  int k, ka, kb;

  da.d = _b2d (a, &ka);
  db.d = _b2d (b, &kb);

  k = ka - kb + 32 * (a->_wds - b->_wds);
  if (k > 0)
    (da.i[1]) += k * ((__uint32_t)0x100000L);
  else
    {
      k = -k;
      (db.i[1]) += k * ((__uint32_t)0x100000L);
    }

  return da.d / db.d;
}


const double
  __mprec_tens[] =
{
  1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9,
  1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19,
  1e20, 1e21, 1e22, 1e23, 1e24

};


const double __mprec_bigtens[] =
{1e16, 1e32, 1e64, 1e128, 1e256};

const double __mprec_tinytens[] =
{1e-16, 1e-32, 1e-64, 1e-128, 1e-256};
double
_mprec_log10(int dig)

{
  double v = 1.0;
  if (dig < 24)
    return __mprec_tens[dig];
  while (dig > 0)
    {
      v *= 10;
      dig--;
    }
  return v;
}
