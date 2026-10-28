/* LBPMATCH module=EBOOT.BIN start=0x08ba2b4c end=0x08ba2ba8 symbol=__sprint lang=c99 cc=gcc402x-O2 */
/* Library source: newlib 1.14.0 libc_stdio/vfprintf.c function __sprint, preprocessed (comments kept), identified by compiled-code signature (lbplib.py) and built with the GCC profile in the header; exact match verified; external names are newlib's, their addresses read from retail. */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
FUNCTION
<<vprintf>>, <<vfprintf>>, <<vsprintf>>---format argument list

INDEX
	vprintf
INDEX
	vfprintf
INDEX
	vsprintf
INDEX
	vsnprintf

ANSI_SYNOPSIS
	#include <stdio.h>
	#include <stdarg.h>
	int vprintf(const char *<[fmt]>, va_list <[list]>);
	int vfprintf(FILE *<[fp]>, const char *<[fmt]>, va_list <[list]>);
	int vsprintf(char *<[str]>, const char *<[fmt]>, va_list <[list]>);
	int vasprintf(char **<[strp]>, const char *<[fmt]>, va_list <[list]>);
	int vsnprintf(char *<[str]>, size_t <[size]>, const char *<[fmt]>,
                      va_list <[list]>);

	int _vprintf_r(struct _reent *<[reent]>, const char *<[fmt]>,
                        va_list <[list]>);
	int _vfprintf_r(struct _reent *<[reent]>, FILE *<[fp]>, const char *<[fmt]>,
                        va_list <[list]>);
	int _vasprintf_r(struct _reent *<[reent]>, char **<[str]>,
                        const char *<[fmt]>, va_list <[list]>);
	int _vsprintf_r(struct _reent *<[reent]>, char *<[str]>,
                        const char *<[fmt]>, va_list <[list]>);
	int _vsnprintf_r(struct _reent *<[reent]>, char *<[str]>, size_t <[size]>,
                         const char *<[fmt]>, va_list <[list]>);

TRAD_SYNOPSIS
	#include <stdio.h>
	#include <varargs.h>
	int vprintf( <[fmt]>, <[list]>)
	char *<[fmt]>;
	va_list <[list]>;

	int vfprintf(<[fp]>, <[fmt]>, <[list]>)
	FILE *<[fp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int vasprintf(<[strp]>, <[fmt]>, <[list]>)
	char **<[strp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int vsprintf(<[str]>, <[fmt]>, <[list]>)
	char *<[str]>;
	char *<[fmt]>;
	va_list <[list]>;

	int vsnprintf(<[str]>, <[size]>, <[fmt]>, <[list]>)
	char *<[str]>;
        size_t <[size]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vprintf_r(<[reent]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vfprintf_r(<[reent]>, <[fp]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	FILE *<[fp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vasprintf_r(<[reent]>, <[strp]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	char **<[strp]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vsprintf_r(<[reent]>, <[str]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	char *<[str]>;
	char *<[fmt]>;
	va_list <[list]>;

	int _vsnprintf_r(<[reent]>, <[str]>, <[size]>, <[fmt]>, <[list]>)
	struct _reent *<[reent]>;
	char *<[str]>;
        size_t <[size]>;
	char *<[fmt]>;
	va_list <[list]>;

DESCRIPTION
<<vprintf>>, <<vfprintf>>, <<vasprintf>>, <<vsprintf>> and <<vsnprintf>> are 
(respectively) variants of <<printf>>, <<fprintf>>, <<asprintf>>, <<sprintf>>,
and <<snprintf>>.  They differ only in allowing their caller to pass the 
variable argument list as a <<va_list>> object (initialized by <<va_start>>) 
rather than directly accepting a variable number of arguments.

RETURNS
The return values are consistent with the corresponding functions:
<<vasprintf>>/<<vsprintf>> returns the number of bytes in the output string,
save that the concluding <<NULL>> is not counted.
<<vprintf>> and <<vfprintf>> return the number of characters transmitted.
If an error occurs, <<vprintf>> and <<vfprintf>> return <<EOF>> and
<<vasprintf>> returns -1.  No error returns occur for <<vsprintf>>.

PORTABILITY
ANSI C requires all three functions.

Supporting OS subroutines required: <<close>>, <<fstat>>, <<isatty>>,
<<lseek>>, <<read>>, <<sbrk>>, <<write>>.
*/






/*
 * Actual printf innards.
 *
 * This code is large and complicated...
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
/* Project-authored stddef.h for the 32-bit little-endian PSP (Allegrex; ILP32 ABI of psp-gcc 3.3.3).
   Written from ISO C 7.17 and the type widths of that ABI. It contains no compiler vendor text.
   A header that needs only some of the types defines __need_size_t, __need_ptrdiff_t, __need_wchar_t,
   __need_wint_t or __need_NULL before including this file (the convention newlib's headers use);
   an include without any of them defines the full ISO set. */
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
typedef unsigned int size_t;




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
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__s' for stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */





/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/* Project-authored stdarg.h for psp-gcc 3.3.3 (MIPS o32, little-endian). Written from ISO C 7.15 and the
   compiler's built-in variable-argument support (__builtin_va_list and the __builtin_va_* operations); it
   contains no compiler vendor text. A header that needs only the list type (stdio.h's prototypes) defines
   __need___va_list first and gets just __gnuc_va_list. */




typedef __builtin_va_list __gnuc_va_list;
/*
 * <sys/reent.h> defines __FILE, _fpos_t.
 * They must be defined there because struct _reent needs them (and we don't
 * want reent.h to include this file.
 */


/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
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
typedef int wchar_t;
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


typedef __FILE FILE;
typedef _fpos_t fpos_t;
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
/* Internal locking macros, used to protect stdio functions.  In the
   general case, expand to nothing. Use __SSTR flag in FILE _flags to
   detect if FILE is private to sprintf/sscanf class of functions; if
   set then do nothing as lock is not initialised. */
        /* RD and WR are never simultaneously asserted */
/*
 * The following three definitions are for ANSI C, which took them
 * from System V, which stupidly took internal interface macros and
 * made them official arguments to setvbuf(), without renaming them.
 * Hence, these ugly _IOxxx names are *supposed* to appear in user code.
 *
 * Although these happen to match their counterparts above, the
 * implementation does not rely on that (so these could be renumbered).
 */
/*
 * Functions defined in ANSI C standard.
 */







FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *, const char *, FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
int fprintf (FILE *, const char *, ...);
int fscanf (FILE *, const char *, ...);
int printf (const char *, ...);
int scanf (const char *, ...);
int sscanf (const char *, const char *, ...);
int vfprintf (FILE *, const char *, __gnuc_va_list);
int vprintf (const char *, __gnuc_va_list);
int vsprintf (char *, const char *, __gnuc_va_list);
int fgetc (FILE *);
char * fgets (char *, int, FILE *);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *, size_t _size, size_t _n, FILE *);
size_t fwrite (const void * , size_t _size, size_t _n, FILE *);



int fgetpos (FILE *, fpos_t *);

int fseek (FILE *, long, int);



int fsetpos (FILE *, const fpos_t *);

long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char *_name, const char *_type);
int sprintf (char *, const char *, ...);
int remove (const char *);
int rename (const char *, const char *);






int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);


int asiprintf (char **, const char *, ...);
int asprintf (char **, const char *, ...);
int dprintf (int, const char *, ...);
int fcloseall (void);
int fiprintf (FILE *, const char *, ...);
int iprintf (const char *, ...);
int siprintf (char *, const char *, ...);
int snprintf (char *, size_t, const char *, ...);
int sniprintf (char *, size_t, const char *, ...);
char * tempnam (const char *, const char *);
int vasiprintf (char **, const char *, __gnuc_va_list);
int vasprintf (char **, const char *, __gnuc_va_list);
int vdprintf (int, const char *, __gnuc_va_list);
int vsniprintf (char *, size_t, const char *, __gnuc_va_list);
int vsnprintf (char *, size_t, const char *, __gnuc_va_list);
int vfiprintf (FILE *, const char *, __gnuc_va_list);
int vfiscanf (FILE *, const char *, __gnuc_va_list);
int vfscanf (FILE *, const char *, __gnuc_va_list);
int viprintf (const char *, __gnuc_va_list);
int viscanf (const char *, __gnuc_va_list);
int vscanf (const char *, __gnuc_va_list);
int vsiscanf (const char *, const char *, __gnuc_va_list);
int vsscanf (const char *, const char *, __gnuc_va_list);



/*
 * Routines in POSIX 1003.1.
 */



FILE * fdopen (int, const char *);

int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);


/*
 * Recursive versions of the above.
 */

int _asiprintf_r (struct _reent *, char **, const char *, ...);
int _asprintf_r (struct _reent *, char **, const char *, ...);
int _dprintf_r (struct _reent *, int, const char *, ...);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
FILE * _fopen_r (struct _reent *, const char *, const char *);
int _fclose_r (struct _reent *, FILE *);
int _fiscanf_r (struct _reent *, FILE *, const char *, ...);
int _fscanf_r (struct _reent *, FILE *, const char *, ...);
int _fseek_r (struct _reent *, FILE *, long, int);
long _ftell_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...);
int _iscanf_r (struct _reent *, const char *, ...);
int _mkstemp_r (struct _reent *, char *);
char * _mktemp_r (struct _reent *, char *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *, ...);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new);

int _scanf_r (struct _reent *, const char *, ...);
int _siprintf_r (struct _reent *, char *, const char *, ...);
int _siscanf_r (struct _reent *, const char *, const char *, ...);
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...);
int _snprintf_r (struct _reent *, char *, size_t, const char *, ...);
int _sprintf_r (struct _reent *, char *, const char *, ...);
int _sscanf_r (struct _reent *, const char *, const char *, ...);
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list);
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list);
int _vdprintf_r (struct _reent *, int, const char *, __gnuc_va_list);
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vfprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list);
int _vprintf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list);
int _vsprintf_r (struct _reent *, char *, const char *, __gnuc_va_list);
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list);
int _vsnprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list);
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vfscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list);
int _vscanf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list);
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list);

ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
/*
 * Routines internal to the implementation.
 */

int __srget (FILE *);
int __swbuf (int, FILE *);

/*
 * Stdio function-access interface.
 */


FILE *funopen (const void * _cookie, int (*readfn)(void * _cookie, char *_buf, int _n), int (*writefn)(void * _cookie, const char *_buf, int _n), fpos_t (*seekfn)(void * _cookie, fpos_t _off, int _whence), int (*closefn)(void * _cookie));
/*
 * The __sfoo macros are here so that we can 
 * define function versions in the C library.
 */
/*
 * This has been tuned to generate reasonable code on the vax using pcc
 */
/* fast always-buffered version, true iff error */




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
/* This header file provides the reentrancy.  */

/* WARNING: All identifiers here must begin with an underscore.  This file is
   included by stdio.h and others and we therefore must only use identifiers
   in the namespace allotted to us.  */
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


/* if do not have #include_next support, then we
   have to define the limits here. */
/* `_GCC_LIMITS_H_' is what GCC's file defines.  */

/* Project-authored limits.h for the PSP (psp-gcc 3.3.3 ABI: 8-bit char, signed by default; 16-bit short;
   32-bit int and long; 64-bit long long; two's complement). Written from ISO C 5.2.4.2.1; it contains no
   compiler vendor text. newlib's limits.h reaches it with #include_next and adds MB_LEN_MAX. */
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
/* For _mbstate_t definition. */

/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/




typedef _mbstate_t mbstate_t;


wint_t btowc (int);
int wctob (wint_t);
size_t mbrlen (const char * , size_t, mbstate_t *);
size_t mbrtowc (wchar_t * , const char * , size_t, mbstate_t *);
size_t _mbrtowc_r (struct _reent *, wchar_t * , const char * , size_t, mbstate_t *);

int mbsinit (const mbstate_t *);
size_t mbsrtowcs (wchar_t * , const char ** , size_t, mbstate_t *);
size_t wcrtomb (char * , wchar_t, mbstate_t *);
size_t _wcrtomb_r (struct _reent *, char * , wchar_t, mbstate_t *);
size_t wcsrtombs (char * , const wchar_t ** , size_t, mbstate_t *);
size_t _wcsrtombs_r (struct _reent *, char * , const wchar_t ** , size_t, mbstate_t *);

wchar_t *wcscat (wchar_t * , const wchar_t *);
wchar_t *wcschr (const wchar_t *, wchar_t);
int wcscmp (const wchar_t *, const wchar_t *);
int wcscoll (const wchar_t *, const wchar_t *);
wchar_t *wcscpy (wchar_t * , const wchar_t *);
size_t wcscspn (const wchar_t *, const wchar_t *);
size_t wcslcat (wchar_t *, const wchar_t *, size_t);
size_t wcslcpy (wchar_t *, const wchar_t *, size_t);
size_t wcslen (const wchar_t *);
wchar_t *wcsncat (wchar_t * , const wchar_t * , size_t);
int wcsncmp (const wchar_t *, const wchar_t *, size_t);
wchar_t *wcsncpy (wchar_t * , const wchar_t * , size_t);
size_t wcsnlen (const wchar_t *, size_t);
wchar_t *wcspbrk (const wchar_t *, const wchar_t *);
wchar_t *wcsrchr (const wchar_t *, wchar_t);
size_t wcsspn (const wchar_t *, const wchar_t *);
wchar_t *wcsstr (const wchar_t *, const wchar_t *);
int wcswidth (const wchar_t *, size_t);
int wcwidth (const wchar_t);
wchar_t *wmemchr (const wchar_t *, wchar_t, size_t);
int wmemcmp (const wchar_t *, const wchar_t *, size_t);
wchar_t *wmemcpy (wchar_t * , const wchar_t * , size_t);
wchar_t *wmemmove (wchar_t *, const wchar_t *, size_t);
wchar_t *wmemset (wchar_t *, wchar_t, size_t);





/*
 * string.h
 *
 * Definitions for memory and string functions.
 */
typedef __gnuc_va_list va_list;
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	%W% (UofMD/Berkeley) %G%
 */

/*
 * Information local to this implementation of stdio,
 * in particular, macros and private variables.
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
/* ANSI C namespace clean utility typedefs */

/* This file defines various typedefs needed by the system calls that support
   the C library.  Basically, they're just the POSIX versions with an '_'
   prepended.  This file lives in the `sys' directory so targets can provide
   their own if desired (or they can put target dependant conditionals here).
*/
extern char **environ;

void _exit (int __status ) __attribute__ ((noreturn));

int access (const char *__path, int __amode );
unsigned alarm (unsigned __secs );
int chdir (const char *__path );
int chmod (const char *__path, mode_t __mode );

int chown (const char *__path, uid_t __owner, gid_t __group );




int close (int __fildes );
char *ctermid (char *__s );
char *cuserid (char *__s );



int dup (int __fildes );
int dup2 (int __fildes, int __fildes2 );



int execl (const char *__path, const char *, ... );
int execle (const char *__path, const char *, ... );
int execlp (const char *__file, const char *, ... );
int execv (const char *__path, char * const __argv[] );
int execve (const char *__path, char * const __argv[], char * const __envp[] );
int execvp (const char *__file, char * const __argv[] );



int fchmod (int __fildes, mode_t __mode );

int fchown (int __fildes, uid_t __owner, gid_t __group );

pid_t fork (void );
long fpathconf (int __fd, int __name );
int fsync (int __fd);
int fdatasync (int __fd);
char *getcwd (char *__buf, size_t __size );




gid_t getegid (void );
uid_t geteuid (void );
gid_t getgid (void );

int getgroups (int __gidsetsize, gid_t __grouplist[] );



char *getlogin (void );



char *getpass (const char *__prompt);
size_t getpagesize (void);



pid_t getpgid (pid_t);
pid_t getpgrp (void );
pid_t getpid (void );
pid_t getppid (void );




uid_t getuid (void );






int isatty (int __fildes );

int lchown (const char *__path, uid_t __owner, gid_t __group );

int link (const char *__path1, const char *__path2 );
int nice (int __nice_value );

off_t lseek (int __fildes, off_t __offset, int __whence );

long pathconf (const char *__path, int __name );
int pause (void );



int pipe (int __fildes[2] );
ssize_t pread (int __fd, void *__buf, size_t __nbytes, off_t __offset);
ssize_t pwrite (int __fd, const void *__buf, size_t __nbytes, off_t __offset);
int read (int __fd, void *__buf, size_t __nbyte );




int rmdir (const char *__path );



void * sbrk (ptrdiff_t __incr);





int setgid (gid_t __gid );




int setpgid (pid_t __pid, pid_t __pgid );
int setpgrp (void );




pid_t setsid (void );

int setuid (uid_t __uid );




unsigned sleep (unsigned int __seconds );
void swab (const void *, void *, ssize_t);
long sysconf (int __name );
pid_t tcgetpgrp (int __fildes );
int tcsetpgrp (int __fildes, pid_t __pgrp_id );
char *ttyname (int __fildes );



int unlink (const char *__path );
int vhangup (void );
int write (int __fd, const void *__buf, size_t __nbyte );






extern char *optarg; /* getopt(3) external variables */
extern int optind, opterr, optopt;
int getopt(int, char * const [], const char *);
extern int optreset; /* getopt(3) external variable */



pid_t vfork (void );

extern char *suboptarg; /* getsubopt(3) external variable */
int getsubopt(char **, char * const *, char **);
int readlink (const char *__path, char *__buf, int __buflen);
int symlink (const char *__name1, const char *__name2);
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
/*
 *  4.8.1 Get Configurable System Variables, P1003.1b-1993, p. 96
 *
 *  NOTE: Table 4-2, Configurable System Variables, p. 96
 */






  /* no _SC_STREAM_MAX */




/* CYGWIN-specific values .. do not touch */




/* end of CYGWIN-specific values */
/*
 *  P1003.1c/D10, p. 52 adds the following.
 */
/* _SC_THREAD_PRIO_PROTECT was _SC_THREAD_PRIO_CEILING in early drafts */
/* FIXME: This is temporary until winsup gets sorted out.  */
extern int __svfscanf_r (struct _reent *,FILE *, const char *,va_list);
extern int __svfiscanf_r (struct _reent *,FILE *, const char *,va_list);
extern FILE *__sfp (struct _reent *);
extern int __sflags (struct _reent *,const char*, int*);
extern int __srefill (FILE *);
extern int __sread (void *, char *, int);
extern int __swrite (void *, char const *, int);
extern _fpos_t __sseek (void *, _fpos_t, int);
extern int __sclose (void *);
extern int __stextmode (int);
extern void __sinit (struct _reent *);
extern void _cleanup_r (struct _reent *);
extern void __smakebuf (FILE *);
extern int _fwalk (struct _reent *, int (*)(FILE *));
extern int _fwalk_reent (struct _reent *, int (*)(struct _reent *, FILE *));
struct _glue * __sfmoreglue (struct _reent *,int n);
extern int __srefill (FILE *fp);

/* Called by the main entry point fns to ensure stdio has been initialized.  */
/* Return true iff the given FILE cannot be written now.  */





/* Test whether the given stdio file has an active ungetc buffer;
   release such a buffer, without restoring ordinary unread data.  */
/* Test for an fgetline() buffer.  */




/* WARNING: _dcvt is defined in the stdlib directory, not here!  */

char *_dcvt (struct _reent *, char *, double, int, int, char, int);
char *_sicvt (char *, short, char);
char *_icvt (char *, int, char);
char *_licvt (char *, long, char);

char *_llicvt (char *, long long, char);
void __sfp_lock_acquire (void);
void __sfp_lock_release (void);
void __sinit_lock_acquire (void);
void __sinit_lock_release (void);


/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/* %W% (Berkeley) %G% */

/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/*
 * I/O descriptors for __sfvwrite().
 */
struct __siov {
        const void * iov_base;
        size_t iov_len;
};
struct __suio {
        struct __siov *uio_iov;
        int uio_iovcnt;
        int uio_resid;
};


extern int __sfvwrite (FILE *, struct __suio *);
extern int __swsetup (FILE *);



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

/* This header file is a modification of mprec.h that only contains floating
   point union code. */







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
/* If we are going to examine or modify specific bits in a double using
   the word0 and/or word1 macros, then we must wrap the double inside
   a union.  This is necessary to avoid undefined behavior according to
   the ANSI C spec.  */
union double_union
{
  double d;
  __uint32_t i[2];
};
/* #define P DBL_MANT_DIG */
/* Ten_pmax = floor(P*log(2)/log(5)) */
/* Bletch = (highest power of 2 < DBL_MAX_10_EXP) / 16 */
/* Quick_max = floor((P-1)*log(FLT_RADIX)/log(10) - 1) */
/* Int_max = floor(P*log(FLT_RADIX)/log(10) - 1) */
/* Currently a test is made to see if long double processing is warranted.
   This could be changed in the future should the _ldtoa_r code be
   preferred over _dtoa_r.  */
/*
 * Flush out all the vectors defined by the given uio,
 * then reset it so that it can be reused.
 */
static int
__sprint(FILE *fp , register struct __suio *uio)


{
        register int err;

        if (uio->uio_resid == 0) {
                uio->uio_iovcnt = 0;
                return (0);
        }
        err = __sfvwrite(fp, uio);
        uio->uio_resid = 0;
        uio->uio_iovcnt = 0;
        return (err);
}

/*
 * Helper function for `fprintf to unbuffered unix file': creates a
 * temporary buffer.  We only work on write-only files; this avoids
 * worries about ungetc buffers and so forth.
 */
static int
__sbprintf(struct _reent *rptr , register FILE *fp , const char *fmt , va_list ap)




{
        int ret;
        FILE fake;
        unsigned char buf[1024];

        /* copy the important variables */
        fake._flags = fp->_flags & ~0x0002;
        fake._file = fp->_file;
        fake._cookie = fp->_cookie;
        fake._write = fp->_write;

        /* set up the buffer */
        fake._bf._base = fake._p = buf;
        fake._bf._size = fake._w = sizeof (buf);
        fake._lbfsize = 0; /* not actually used, but Just In Case */

        (0);


        /* do the work, then copy any error status */
        ret = _vfprintf_r (rptr, &fake, fmt, ap);
        if (ret >= 0 && fflush(&fake))
                ret = (-1);
        if (fake._flags & 0x0040)
                fp->_flags |= 0x0040;


        (0);

        return (ret);
}




/*
	locale.h
	Values appropriate for the formatting of monetary and other
	numberic quantities.
*/





/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */


struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
};


char *setlocale (int category, const char *locale);
struct lconv *localeconv (void);


struct _reent;
char *_setlocale_r (struct _reent *, int category, const char *locale);
struct lconv *_localeconv_r (struct _reent *);





/* math.h -- Definitions for the math floating point package.  */
/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *	%W% (Berkeley) %G%
 */

/*
 * Floating point scanf/printf (input/output) definitions.
 */


/* 11-bit exponent (VAX G floating point) is 308 decimal digits */





/* 128 bit fraction takes up 39 decimal digits; max reasonable precision */
static char *
cvt (struct _reent *, double, int, int, char *, int *, int, int *);






static int exponent (char *, int, int);
typedef long * quad_ptr_t;
typedef void * void_ptr_t;
typedef char * char_ptr_t;
typedef long * long_ptr_t;
typedef int * int_ptr_t;
typedef short * short_ptr_t;
/*
 * Macros for converting digits to letters and vice versa
 */




/*
 * Flags used during conversion.
 */
int _vfprintf_r (struct _reent *, FILE *, const char *, va_list);

int
vfprintf(FILE * fp , const char *fmt0 , va_list ap)



{
  int result;
  result = _vfprintf_r (_impure_ptr, fp, fmt0, ap);
  return result;
}

int
_vfprintf_r(struct _reent *data , FILE * fp , const char *fmt0 , va_list ap)




{
        register char *fmt; /* format string */
        register int ch; /* character from fmt */
        register int n, m; /* handy integers (short term usage) */
        register char *cp; /* handy char pointer (short term usage) */
        register struct __siov *iovp;/* for PRINT macro */
        register int flags; /* flags as above */
        char *fmt_anchor; /* current format spec being processed */
        int N; /* arg number */
        int arg_index; /* index into args processed directly */
        int ret; /* return value accumulator */
        int width; /* width from format (%8d), or 0 */
        int prec; /* precision from format (%.3d), or -1 */
        char sign; /* sign prefix (' ', '+', '-', or \0) */

        char *decimal_point = localeconv()->decimal_point;
        char softsign; /* temporary negative sign for floats */

        union { int i; double d; } _double_ = {0};






        int expt; /* integer value of exponent */
        int expsize = 0; /* character count for expstr */
        int ndig; /* actual number of digits returned by cvt */
        char expstr[7]; /* buffer for exponent string */

        unsigned long _uquad; /* integer arguments %[diouxX] */
        enum { OCT, DEC, HEX } base;/* base for [diouxX] conversion */
        int dprec; /* a copy of prec if [diouxX], 0 otherwise */
        int realsz; /* field size expanded by dprec */
        int size; /* size of converted field or string */
        char *xdigs = ((void *)0); /* digits for [xX] conversion */

        struct __suio uio; /* output information: summary */
        struct __siov iov[8];/* ... and individual io vectors */
        char buf[(308 +39 +1)]; /* space for %c, %[diouxX], %[eEfgG] */
        char ox[2]; /* space for 0x hex-prefix */




        char *malloc_buf = ((void *)0);/* handy pointer for malloced buffers */

        /*
	 * Choose PADSIZE to trade efficiency vs. size.  If larger printf
	 * fields occur frequently, increase PADSIZE and make the initialisers
	 * below longer.
	 */

        static const char blanks[16] =
         {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
        static const char zeroes[16] =
         {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};




        /*
	 * BEWARE, these `goto error' on error, and PAD uses `n'.
	 */
        /* Macros to support positional arguments */
        /*
	 * To extend shorts properly, we need both signed and unsigned
	 * argument extraction methods.
	 */
        do { if ((data) && !(data)->__sdidinit) __sinit (data); } while (0);
        (((fp)->_flags & 0x0200) ? 0 : (0));

        /* sorry, fprintf(read_only_file, "") returns EOF, not 0 */
        if (((((fp)->_flags & 0x0008) == 0 || (fp)->_bf._base == ((void *)0)) && __swsetup(fp))) {
                (((fp)->_flags & 0x0200) ? 0 : (0));
                return ((-1));
        }

        /* optimise fprintf(stderr) (and other unbuffered Unix files) */
        if ((fp->_flags & (0x0002|0x0008|0x0010)) == (0x0002|0x0008) &&
            fp->_file >= 0) {
                (((fp)->_flags & 0x0200) ? 0 : (0));
                return (__sbprintf (data, fp, fmt0, ap));
        }

        fmt = (char *)fmt0;
        uio.uio_iov = iovp = iov;
        uio.uio_resid = 0;
        uio.uio_iovcnt = 0;
        ret = 0;
        arg_index = 0;







        /*
	 * Scan the format for conversions (`%' character).
	 */
        for (;;) {
                cp = fmt;







                while (*fmt != '\0' && *fmt != '%')
                    fmt += 1;

                if ((m = fmt - cp) != 0) {
                        { iovp->iov_base = (cp); iovp->iov_len = (m); uio.uio_resid += (m); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                        ret += m;
                }




                if (*fmt == '\0')
                    goto done;

                fmt_anchor = fmt;
                fmt++; /* skip over '%' */

                flags = 0;
                dprec = 0;
                width = 0;
                prec = -1;
                sign = '\0';
                N = arg_index;




rflag: ch = *fmt++;
reswitch: switch (ch) {
                case ' ':
                        /*
			 * ``If the space and + flags both appear, the space
			 * flag will be ignored.''
			 *	-- ANSI X3J11
			 */
                        if (!sign)
                                sign = ' ';
                        goto rflag;
                case '#':
                        flags |= 0x001;
                        goto rflag;
                case '*':
                        n = N;
                        /*
			 * ``A negative field width argument is taken as a
			 * - flag followed by a positive field width.''
			 *	-- ANSI X3J11
			 * They don't exclude field widths read from args.
			 */
                        width = (__builtin_va_arg(ap,int));



                        if (width >= 0)
                                goto rflag;
                        width = -width;
                        /* FALLTHROUGH */
                case '-':
                        flags |= 0x004;
                        goto rflag;
                case '+':
                        sign = '+';
                        goto rflag;
                case '.':
                        if ((ch = *fmt++) == '*') {
                                n = N;
                                prec = (__builtin_va_arg(ap,int));



                                if (prec < 0)
                                        prec = -1;
                                goto rflag;
                        }
                        n = 0;
                        while (((unsigned)((ch) - '0') <= 9)) {
                                n = 10 * n + ((ch) - '0');
                                ch = *fmt++;
                        }
                        prec = n < 0 ? -1 : n;
                        goto reswitch;
                case '0':
                        /*
			 * ``Note that 0 is taken as a flag, not as the
			 * beginning of a field width.''
			 *	-- ANSI X3J11
			 */
                        flags |= 0x080;
                        goto rflag;
                case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                        n = 0;
                        do {
                                n = 10 * n + ((ch) - '0');
                                ch = *fmt++;
                        } while (((unsigned)((ch) - '0') <= 9));
                        width = n;
                        goto reswitch;

                case 'L':
                        flags |= 0x008;
                        goto rflag;

                case 'h':
                        flags |= 0x040;
                        goto rflag;
                case 'l':
                        if (*fmt == 'l') {
                                fmt++;
                                flags |= 0x010;
                        } else {
                                flags |= 0x010;
                        }
                        goto rflag;
                case 'q':
                        flags |= 0x010;
                        goto rflag;
                case 'c':
                case 'C':
                        cp = buf;
                        if (ch == 'C' || (flags & 0x010)) {
                                mbstate_t ps;

                                memset ((void *)&ps, '\0', sizeof (mbstate_t));
                                if ((size = (int)_wcrtomb_r (data, cp,
                                               (wchar_t)(__builtin_va_arg(ap,wint_t)),
                                                &ps)) == -1) {
                                        fp->_flags |= 0x0040;
                                        goto error;
                                }
                        }
                        else {
                                *cp = (__builtin_va_arg(ap,int));
                                size = 1;
                        }
                        sign = '\0';
                        break;
                case 'D':
                        flags |= 0x010;
                        /*FALLTHROUGH*/
                case 'd':
                case 'i':
                        _uquad = (flags&0x010 ? (__builtin_va_arg(ap,long)) : flags&0x040 ? (long)(short)(__builtin_va_arg(ap,int)) : (long)(__builtin_va_arg(ap,int)));



                        if ((long) _uquad < 0)

                        {

                                _uquad = -_uquad;
                                sign = '-';
                        }
                        base = DEC;
                        goto number;

                case 'e':
                case 'E':
                case 'f':
                case 'F':
                case 'g':
                case 'G':
                        if (prec == -1) {
                                prec = 6;
                        } else if ((ch == 'g' || ch == 'G') && prec == 0) {
                                prec = 1;
                        }


                        if (flags & 0x008) {
                                (_double_.d) = (double) (__builtin_va_arg(ap,long double));
                        } else {
                                (_double_.d) = (__builtin_va_arg(ap,double));
                        }

                        /* do this before tricky precision changes */
                        if (isinf ((_double_.d))) {
                                if ((_double_.d) < 0)
                                        sign = '-';
                                if (ch == 'E' || ch == 'F' || ch == 'G')
                                        cp = "INF";
                                else
                                        cp = "inf";
                                size = 3;
                                break;
                        }
                        if (isnan ((_double_.d))) {
                                if (ch == 'E' || ch == 'F' || ch == 'G')
                                        cp = "NAN";
                                else
                                        cp = "nan";
                                size = 3;
                                break;
                        }
                        flags |= 0x100;

                        cp = cvt (data, (_double_.d), prec, flags, &softsign,
                                &expt, ch, &ndig);

                        if (ch == 'g' || ch == 'G') {
                                if (expt <= -4 || expt > prec)
                                        ch = (ch == 'g') ? 'e' : 'E';
                                else
                                        ch = 'g';
                        }
                        if (ch <= 'e') { /* 'e' or 'E' fmt */
                                --expt;
                                expsize = exponent (expstr, expt, ch);
                                size = expsize + ndig;
                                if (ndig > 1 || flags & 0x001)
                                        ++size;
                        } else if (ch == 'f') { /* f fmt */
                                if (expt > 0) {
                                        size = expt;
                                        if (prec || flags & 0x001)
                                                size += prec + 1;
                                } else /* "0.X" */
                                        size = (prec || flags & 0x001)
                                                  ? prec + 2
                                                  : 1;
                        } else if (expt >= ndig) { /* fixed g fmt */
                                size = expt;
                                if (flags & 0x001)
                                        ++size;
                        } else
                                size = ndig + (expt > 0 ?
                                        1 : 2 - expt);

                        if (softsign)
                                sign = '-';
                        break;

                case 'n':





                        if (flags & 0x010)
                                *(__builtin_va_arg(ap,long_ptr_t)) = ret;
                        else if (flags & 0x040)
                                *(__builtin_va_arg(ap,short_ptr_t)) = ret;
                        else
                                *(__builtin_va_arg(ap,int_ptr_t)) = ret;
                        continue; /* no output */
                case 'O':
                        flags |= 0x010;
                        /*FALLTHROUGH*/
                case 'o':
                        _uquad = (flags&0x010 ? (__builtin_va_arg(ap,u_long)) : flags&0x040 ? (u_long)(u_short)(__builtin_va_arg(ap,int)) : (u_long)(__builtin_va_arg(ap,u_int)));
                        base = OCT;
                        goto nosign;
                case 'p':
                        /*
			 * ``The argument shall be a pointer to void.  The
			 * value of the pointer is converted to a sequence
			 * of printable characters, in an implementation-
			 * defined manner.''
			 *	-- ANSI X3J11
			 */
                        /* NOSTRICT */
                        _uquad = (u_long)(unsigned long)(__builtin_va_arg(ap,void_ptr_t));
                        base = HEX;
                        xdigs = "0123456789abcdef";
                        flags |= 0x002;
                        ch = 'x';
                        goto nosign;
                case 's':
                case 'S':
                        sign = '\0';
                        if ((cp = (__builtin_va_arg(ap,char_ptr_t))) == ((void *)0)) {
                                cp = "(null)";
                                size = 6;
                        }
                        else if (ch == 'S' || (flags & 0x010)) {
                                mbstate_t ps;
                                const wchar_t *wcp;

                                wcp = (const wchar_t *)cp;
                                size = m = 0;
                                memset ((void *)&ps, '\0', sizeof (mbstate_t));

                                /* Count number of bytes needed for multibyte
				   string that will be produced from widechar
				   string.  */
                                if (prec >= 0) {
                                        while (1) {
                                                if (wcp[m] == L'\0')
                                                        break;
                                                if ((n = (int)_wcrtomb_r (data,
                                                     buf, wcp[m], &ps)) == -1) {
                                                        fp->_flags |= 0x0040;
                                                        goto error;
                                                }
                                                if (n + size > prec)
                                                        break;
                                                m += 1;
                                                size += n;
                                                if (size == prec)
                                                        break;
                                        }
                                }
                                else {
                                        if ((size = (int)_wcsrtombs_r (data,
                                                   ((void *)0), &wcp, 0, &ps)) == -1) {
                                                fp->_flags |= 0x0040;
                                                goto error;
                                        }
                                        wcp = (const wchar_t *)cp;
                                }

                                if (size == 0)
                                        break;

                                if ((malloc_buf =
                                    (char *)_malloc_r (data, size + 1)) == ((void *)0)) {
                                        fp->_flags |= 0x0040;
                                        goto error;
                                }

                                /* Convert widechar string to multibyte string. */
                                memset ((void *)&ps, '\0', sizeof (mbstate_t));
                                if (_wcsrtombs_r (data, malloc_buf,
                                                 &wcp, size, &ps) != size) {
                                        fp->_flags |= 0x0040;
                                        goto error;
                                }
                                cp = malloc_buf;
                                cp[size] = '\0';
                        }
                        else if (prec >= 0) {
                                /*
				 * can't use strlen; can only look for the
				 * NUL in the first `prec' characters, and
				 * strlen () will go further.
				 */
                                char *p = memchr (cp, 0, prec);

                                if (p != ((void *)0)) {
                                        size = p - cp;
                                        if (size > prec)
                                                size = prec;
                                } else
                                        size = prec;
                        } else
                                size = strlen (cp);

                        break;
                case 'U':
                        flags |= 0x010;
                        /*FALLTHROUGH*/
                case 'u':
                        _uquad = (flags&0x010 ? (__builtin_va_arg(ap,u_long)) : flags&0x040 ? (u_long)(u_short)(__builtin_va_arg(ap,int)) : (u_long)(__builtin_va_arg(ap,u_int)));
                        base = DEC;
                        goto nosign;
                case 'X':
                        xdigs = "0123456789ABCDEF";
                        goto hex;
                case 'x':
                        xdigs = "0123456789abcdef";
hex: _uquad = (flags&0x010 ? (__builtin_va_arg(ap,u_long)) : flags&0x040 ? (u_long)(u_short)(__builtin_va_arg(ap,int)) : (u_long)(__builtin_va_arg(ap,u_int)));
                        base = HEX;
                        /* leading 0x/X only if non-zero */
                        if (flags & 0x001 && _uquad != 0)
                                flags |= 0x002;

                        /* unsigned conversions */
nosign: sign = '\0';
                        /*
			 * ``... diouXx conversions ... if a precision is
			 * specified, the 0 flag will be ignored.''
			 *	-- ANSI X3J11
			 */
number: if ((dprec = prec) >= 0)
                                flags &= ~0x080;

                        /*
			 * ``The result of converting a zero value with an
			 * explicit precision of zero is no characters.''
			 *	-- ANSI X3J11
			 */
                        cp = buf + (308 +39 +1);
                        if (_uquad != 0 || prec != 0) {
                                /*
				 * Unsigned mod is hard, and unsigned mod
				 * by a constant is easier than that by
				 * a variable; hence this switch.
				 */
                                switch (base) {
                                case OCT:
                                        do {
                                                *--cp = ((_uquad & 7) + '0');
                                                _uquad >>= 3;
                                        } while (_uquad);
                                        /* handle octal leading 0 */
                                        if (flags & 0x001 && *cp != '0')
                                                *--cp = '0';
                                        break;

                                case DEC:
                                        /* many numbers are 1 digit */
                                        while (_uquad >= 10) {
                                                *--cp = ((_uquad % 10) + '0');
                                                _uquad /= 10;
                                        }
                                        *--cp = ((_uquad) + '0');
                                        break;

                                case HEX:
                                        do {
                                                *--cp = xdigs[_uquad & 15];
                                                _uquad >>= 4;
                                        } while (_uquad);
                                        break;

                                default:
                                        cp = "bug in vfprintf: bad base";
                                        size = strlen (cp);
                                        goto skipsize;
                                }
                        }
                       /*
			* ...result is to be converted to an 'alternate form'.
			* For o conversion, it increases the precision to force
			* the first digit of the result to be a zero."
			*     -- ANSI X3J11
			*
			* To demonstrate this case, compile and run:
                        *    printf ("%#.0o",0);
			*/
                       else if (base == OCT && (flags & 0x001))
                         *--cp = '0';

                        size = buf + (308 +39 +1) - cp;
                skipsize:
                        break;
                default: /* "%?" prints ?, unless ? is NUL */
                        if (ch == '\0')
                                goto done;
                        /* pretend it was %c with argument ch */
                        cp = buf;
                        *cp = ch;
                        size = 1;
                        sign = '\0';
                        break;
                }

                /*
		 * All reasonable formats wind up here.  At this point, `cp'
		 * points to a string which (if not flags&LADJUST) should be
		 * padded out to `width' places.  If flags&ZEROPAD, it should
		 * first be prefixed by any sign or other prefix; otherwise,
		 * it should be blank padded before the prefix is emitted.
		 * After any left-hand padding and prefixing, emit zeroes
		 * required by a decimal [diouxX] precision, then print the
		 * string proper, then emit zeroes required by any leftover
		 * floating precision; finally, if LADJUST, pad with blanks.
		 *
		 * Compute actual size, so we know how much to pad.
		 * size excludes decimal prec; realsz includes it.
		 */
                realsz = dprec > size ? dprec : size;
                if (sign)
                        realsz++;
                else if (flags & 0x002)
                        realsz+= 2;

                /* right-adjusting blank padding */
                if ((flags & (0x004|0x080)) == 0)
                        { if ((n = (width - realsz)) > 0) { while (n > 16) { { iovp->iov_base = (blanks); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (blanks); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };

                /* prefix */
                if (sign) {
                        { iovp->iov_base = (&sign); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                } else if (flags & 0x002) {
                        ox[0] = '0';
                        ox[1] = ch;
                        { iovp->iov_base = (ox); iovp->iov_len = (2); uio.uio_resid += (2); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                }

                /* right-adjusting zero padding */
                if ((flags & (0x004|0x080)) == 0x080)
                        { if ((n = (width - realsz)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };

                /* leading zeroes from decimal precision */
                { if ((n = (dprec - size)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };

                /* the string or number proper */

                if ((flags & 0x100) == 0) {
                        { iovp->iov_base = (cp); iovp->iov_len = (size); uio.uio_resid += (size); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                } else { /* glue together f_p fragments */
                        if (ch >= 'f') { /* 'f' or 'g' */
                                if ((_double_.d) == 0) {
                                        /* kludge for __dtoa irregularity */
                                        { iovp->iov_base = ("0"); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        if (expt < ndig || (flags & 0x001) != 0) {
                                                { iovp->iov_base = (decimal_point); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                                { if ((n = (ndig - 1)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };
                                        }
                                } else if (expt <= 0) {
                                        { iovp->iov_base = ("0"); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        if(expt || ndig) {
                                                { iovp->iov_base = (decimal_point); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                                { if ((n = (-expt)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };
                                                { iovp->iov_base = (cp); iovp->iov_len = (ndig); uio.uio_resid += (ndig); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        }
                                } else if (expt >= ndig) {
                                        { iovp->iov_base = (cp); iovp->iov_len = (ndig); uio.uio_resid += (ndig); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        { if ((n = (expt - ndig)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };
                                        if (flags & 0x001)
                                                { iovp->iov_base = ("."); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                } else {
                                        { iovp->iov_base = (cp); iovp->iov_len = (expt); uio.uio_resid += (expt); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        cp += expt;
                                        { iovp->iov_base = ("."); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        { iovp->iov_base = (cp); iovp->iov_len = (ndig-expt); uio.uio_resid += (ndig-expt); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                }
                        } else { /* 'e' or 'E' */
                                if (ndig > 1 || flags & 0x001) {
                                        ox[0] = *cp++;
                                        ox[1] = '.';
                                        { iovp->iov_base = (ox); iovp->iov_len = (2); uio.uio_resid += (2); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                       if ((_double_.d)) {
                                                { iovp->iov_base = (cp); iovp->iov_len = (ndig-1); uio.uio_resid += (ndig-1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                        } else /* 0.[0..] */
                                                /* __dtoa irregularity */
                                                { if ((n = (ndig - 1)) > 0) { while (n > 16) { { iovp->iov_base = (zeroes); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (zeroes); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };
                                } else /* XeYYY */
                                        { iovp->iov_base = (cp); iovp->iov_len = (1); uio.uio_resid += (1); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                                { iovp->iov_base = (expstr); iovp->iov_len = (expsize); uio.uio_resid += (expsize); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } };
                        }
                }



                /* left-adjusting padding (always blank) */
                if (flags & 0x004)
                        { if ((n = (width - realsz)) > 0) { while (n > 16) { { iovp->iov_base = (blanks); iovp->iov_len = (16); uio.uio_resid += (16); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; n -= 16; } { iovp->iov_base = (blanks); iovp->iov_len = (n); uio.uio_resid += (n); iovp++; if (++uio.uio_iovcnt >= 8) { if (__sprint(fp, &uio)) goto error; iovp = iov; } }; } };

                /* finally, adjust ret */
                ret += width > realsz ? width : realsz;

                { if (uio.uio_resid && __sprint(fp, &uio)) goto error; uio.uio_iovcnt = 0; iovp = iov; }; /* copy out the I/O vectors */

                if (malloc_buf != ((void *)0)) {
                        _free_r (data, malloc_buf);
                        malloc_buf = ((void *)0);
                }
        }
done:
        { if (uio.uio_resid && __sprint(fp, &uio)) goto error; uio.uio_iovcnt = 0; iovp = iov; };
error:
        if (malloc_buf != ((void *)0))
                _free_r (data, malloc_buf);
        (((fp)->_flags & 0x0200) ? 0 : (0));
        return ((((fp)->_flags & 0x0040) != 0) ? (-1) : ret);
        /* NOTREACHED */
}




extern char *_dtoa_r (struct _reent *, double, int, int, int *, int *, char **);
static char *
cvt(struct _reent *data , double value , int ndigits , int flags , char *sign , int *decpt , int ch , int *length)
{
        int mode, dsgn;
        char *digits, *bp, *rve;

        union double_union tmp;
        if (ch == 'f') {
                mode = 3; /* ndigits after the decimal point */
        } else {
                /* To obtain ndigits after the decimal point for the 'e' 
		 * and 'E' formats, round to ndigits + 1 significant 
		 * figures.
		 */
                if (ch == 'e' || ch == 'E') {
                        ndigits++;
                }
                mode = 2; /* ndigits significant digits */
        }


        tmp.d = value;

        if ((tmp.i[1]) & ((__uint32_t)0x80000000L)) { /* this will check for < 0 and -0.0 */
                value = -value;
                *sign = '-';
        } else
                *sign = '\000';

        digits = _dtoa_r (data, value, mode, ndigits, decpt, &dsgn, &rve);
        if ((ch != 'g' && ch != 'G') || flags & 0x001) { /* Print trailing zeros */
                bp = digits + ndigits;
                if (ch == 'f') {
                        if (*digits == '0' && value)
                                *decpt = -ndigits + 1;
                        bp += *decpt;
                }
                if (value == 0) /* kludge for __dtoa irregularity */
                        rve = bp;
                while (rve < bp)
                        *rve++ = '0';
        }
        *length = rve - digits;
        return (digits);
}

static int
exponent(char *p0 , int exp , int fmtch)



{
        register char *p, *t;
        char expbuf[40];

        p = p0;
        *p++ = fmtch;
        if (exp < 0) {
                exp = -exp;
                *p++ = '-';
        }
        else
                *p++ = '+';
        t = expbuf + 40;
        if (exp > 9) {
                do {
                        *--t = ((exp % 10) + '0');
                } while ((exp /= 10) > 9);
                *--t = ((exp) + '0');
                for (; t < expbuf + 40; *p++ = *t++);
        }
        else {
                *p++ = '0';
                *p++ = ((exp) + '0');
        }
        return (p - p0);
}
