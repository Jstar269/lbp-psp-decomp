/* LBPMATCH module=EBOOT.BIN start=0x08b9cd58 end=0x08b9cdb0 symbol=std lang=c99 cc=gcc171-O2 */
/* Clone of hst-decomp src/eboot/std_0000f13c_0000f13c.c (lbpxclone.py tag x1): addresses substituted; exact match verified; names and types await human review. */
/* Library source: newlib 1.14.0 libc_stdio/findfp.c function std, preprocessed (comments kept), identified by compiled-code signature (hstlib.py) and built with the GCC profile in the header; exact match verified; external names are newlib's, their addresses read from retail. */
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
/* No user fns here.  Pesch 15apr92. */


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


/* Provide support for both ANSI and non-ANSI environments.  */

/* Some ANSI environments are "broken" in the sense that __STDC__ cannot be
   relied upon to have it's intended meaning.  Therefore we must use our own
   concoction: _HAVE_STDC.  Always use _HAVE_STDC instead of __STDC__ in newlib
   sources!

   To get a strict ANSI C environment, define macro __STRICT_ANSI__.  This will
   "comment out" the non-ANSI parts of the ANSI header files (non-ANSI header
   files aren't affected).  */
/*
 * Flag values for open(2) and fcntl(2)
 * The kernel adds 1 to the open modes to turn it into some
 * combination of FREAD and FWRITE.
 */
/*	O_NDELAY	_FNDELAY 	set in include/fcntl.h */
/*	O_NDELAY	_FNBIO 		set in include/fcntl.h */


/* For machines which care - */
/*
 * Flags that work for fcntl(fd, F_SETFL, FXXXX)
 */







/*
 * Flags that are disallowed for fcntl's (FCNTLCANT);
 * used for opens, internal state, or locking.
 */







/*
 * The rest of the flags, used only for opens
 */
/* XXX close on exec request; must match UF_EXCLOSE in user.h */


/* fcntl(2) requests */
/* fcntl(2) flags (l_type field of flock structure) */







/*#include <sys/stdtypes.h>*/


/* file segment locking set data type - information passed to system by user */
struct flock {
        short l_type; /* F_RDLCK, F_WRLCK, or F_UNLCK */
        short l_whence; /* flag to choose starting offset */
        long l_start; /* relative offset, in bytes */
        long l_len; /* length, in bytes; 0 means lock to EOF */
        short l_pid; /* returned with F_GETLK */
        short l_xxx; /* reserved for future use */
};



/* extended file segment locking set data type */
struct eflock {
        short l_type; /* F_RDLCK, F_WRLCK, or F_UNLCK */
        short l_whence; /* flag to choose starting offset */
        long l_start; /* relative offset, in bytes */
        long l_len; /* length, in bytes; 0 means lock to EOF */
        short l_pid; /* returned with F_GETLK */
        short l_xxx; /* reserved for future use */
        long l_rpid; /* Remote process id wanting this lock */
        long l_rsys; /* Remote system id wanting this lock */
};




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
 * time.h
 * 
 * Struct and function declarations for dealing with time.
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
/* Get _CLOCKS_PER_SEC_ */
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


struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t);

char *asctime_r (const struct tm *, char *);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *, struct tm *);
struct tm *localtime_r (const time_t *, struct tm *);








char *strptime (const char *, const char *, struct tm *);
void tzset (void);
void _tzset_r (struct _reent *);

typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset; /* Match type of _timezone. */
} __tzrule_type;

typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;

__tzinfo_type *__gettzinfo (void);

/* getdate functions */
/* defines for the opengroup specifications Derived from Issue 1 of the SVID.  */
extern long _timezone;
extern int _daylight;
extern char *_tzname[2];

/* POSIX defines the external tzname being defined in time.h */
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
/* CPU-time Clock Attributes, P1003.4b/D8, p. 54 */

/* values for the clock enable attribute */




/* values for the pthread cputime_clock_allowed attribute */


                           /*   CPU-time clock attached to that thread */
                           /*   shall be accessible. */

                           /*   thread shall not have a CPU-time clock */
                           /*   accessible. */

/* Manifest Constants, P1003.1b-1993, p. 262 */



/* Flag indicating time is "absolute" with respect to the clock
   associated with a time.  */



/* Manifest Constants, P1003.4b/D8, p. 55 */
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
/* dj's stat defines _STAT_H_ */


/* It is intended that the layout of this structure not change when the
   sizes of any of the basic types change (short, int, long) [via a compile
   time option].  */







struct stat
{
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;
  /* SysV/sco doesn't have the rest... But Solaris, eabi does.  */





  time_t st_atime;
  long st_spare1;
  time_t st_mtime;
  long st_spare2;
  time_t st_ctime;
  long st_spare3;
  long st_blksize;
  long st_blocks;
  long st_spare4[2];

};
int chmod ( const char *__path, mode_t __mode );
int fchmod (int __fd, mode_t __mode);
int fstat ( int __fd, struct stat *__sbuf );
int mkdir ( const char *_path, mode_t __mode );
int mkfifo ( const char *__path, mode_t __mode );
int stat ( const char *__path, struct stat *__sbuf );
mode_t umask ( mode_t __mask );






/* Provide prototypes for most of the _<systemcall> names that are
   provided in newlib for some compilers.  */
extern int open (const char *, int, ...);
extern int creat (const char *, mode_t);
extern int fcntl (int, int, ...);

/* Provide _<systemcall> prototypes for functions provided by some versions
   of newlib.  */
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
typedef __gnuc_va_list va_list;
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


static void
std(FILE *ptr , int flags , int file , struct _reent *data)




{
  ptr->_p = 0;
  ptr->_r = 0;
  ptr->_w = 0;
  ptr->_flags = flags;
  ptr->_file = file;
  ptr->_bf._base = 0;
  ptr->_bf._size = 0;
  ptr->_lbfsize = 0;
  ptr->_cookie = ptr;
  ptr->_read = __sread;
  ptr->_write = __swrite;
  ptr->_seek = __sseek;
  ptr->_close = __sclose;

  (0);
  /*
   * #else
   * lock is already initialized in __sfp
   */






}

struct _glue *
__sfmoreglue(struct _reent *d , register int n)


{
  struct _glue *g;
  FILE *p;

  g = (struct _glue *) _malloc_r (d, sizeof (*g) + n * sizeof (FILE));
  if (g == ((void *)0))
    return ((void *)0);
  p = (FILE *) (g + 1);
  g->_next = ((void *)0);
  g->_niobs = n;
  g->_iobs = p;
  memset (p, 0, n * sizeof (FILE));
  return g;
}

/*
 * Find a free FILE for fopen et al.
 */

FILE *
__sfp(struct _reent *d)

{
  FILE *fp;
  int n;
  struct _glue *g;

  __sfp_lock_acquire ();

  if (!_global_impure_ptr->__sdidinit)
    __sinit (_global_impure_ptr);
  for (g = &_global_impure_ptr->__sglue;; g = g->_next)
    {
      for (fp = g->_iobs, n = g->_niobs; --n >= 0; fp++)
        if (fp->_flags == 0)
          goto found;
      if (g->_next == ((void *)0) &&
          (g->_next = __sfmoreglue (d, 4)) == ((void *)0))
        break;
    }
  __sfp_lock_release ();
  d->_errno = 12;
  return ((void *)0);

found:
  fp->_file = -1; /* no file */
  fp->_flags = 1; /* reserve this slot; caller sets real flags */

  (0);

  __sfp_lock_release ();

  fp->_p = ((void *)0); /* no current pointer */
  fp->_w = 0; /* nothing to read or write */
  fp->_r = 0;
  fp->_bf._base = ((void *)0); /* no buffer */
  fp->_bf._size = 0;
  fp->_lbfsize = 0; /* not line buffered */
  /* fp->_cookie = <any>; */ /* caller sets cookie, _read/_write etc */
  fp->_ub._base = ((void *)0); /* no ungetc buffer */
  fp->_ub._size = 0;
  fp->_lb._base = ((void *)0); /* no line buffer */
  fp->_lb._size = 0;

  return fp;
}

/*
 * exit() calls _cleanup() through *__cleanup, set whenever we
 * open or buffer a file.  This chicanery is done so that programs
 * that do not use stdio need not link it all in.
 *
 * The name `_cleanup' is, alas, fairly well known outside stdio.
 */

void
_cleanup_r(struct _reent *ptr)

{
  (void) _fwalk(ptr, fclose);
  /* _CAST_VOID _fwalk (ptr, fflush); */ /* `cheating' */
}


void
_cleanup(void)
{
  _cleanup_r (_global_impure_ptr);
}


/*
 * __sinit() is called whenever stdio's internal variables must be set up.
 */

void
__sinit(struct _reent *s)

{
  __sinit_lock_acquire ();

  if (s->__sdidinit)
    {
      __sinit_lock_release ();
      return;
    }

  /* make sure we clean up on exit */
  s->__cleanup = _cleanup_r; /* conservative */
  s->__sdidinit = 1;

  s->__sglue._next = ((void *)0);

  s->__sglue._niobs = 3;
  s->__sglue._iobs = &s->__sf[0];
  std (s->_stdin, 0x0004, 0, s);

  /* on platforms that have true file system I/O, we can verify whether stdout 
     is an interactive terminal or not.  For all other platforms, we will
     default to line buffered mode here.  */



  std (s->_stdout, 0x0008 | 0x0001, 1, s);


  std (s->_stderr, 0x0008 | 0x0002, 2, s);

  __sinit_lock_release ();
}



static int __sfp_lock = 0;;
static int __sinit_lock = 0;;

void
__sfp_lock_acquire(void)
{
  (0);
}

void
__sfp_lock_release(void)
{
  (0);
}

void
__sinit_lock_acquire(void)
{
  (0);
}

void
__sinit_lock_release(void)
{
  (0);
}

/* Walkable file locking routine.  */
static int
__fp_lock(FILE * ptr)

{
  (((ptr)->_flags & 0x0200) ? 0 : (0));

  return 0;
}

/* Walkable file unlocking routine.  */
static int
__fp_unlock(FILE * ptr)

{
  (((ptr)->_flags & 0x0200) ? 0 : (0));

  return 0;
}

void
__fp_lock_all(void)
{
  __sfp_lock_acquire ();

  (void) _fwalk (_impure_ptr, __fp_lock);
}

void
__fp_unlock_all(void)
{
  (void) _fwalk (_impure_ptr, __fp_unlock);

  __sfp_lock_release ();
}
