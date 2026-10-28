#!/bin/sh
# SPDX-License-Identifier: GPL-3.0-or-later
# Code-generation fingerprint of an installed GCC 4.x PSP compiler, independent of where it is installed.
#
#   sh fingerprint.sh INSTALL_DIR [GCC_4_0_4_TARBALL]
#
# Compiles every GCC 4.0.4 C torture compile test (gcc/testsuite/gcc.c-torture/compile/*.c from the verified
# gcc-4.0.4.tar.bz2; default $LBP_GCC4_DL, else $LBP_GCC4_ROOT/dl, else $HOME/lbp-gcc4/dl) with
# INSTALL_DIR/bin/psp-gcc -S, once as C (cc1) and once as C++ (cc1plus), with
#   -Os -G0 -fno-merge-constants -mpreferred-stack-boundary=4 -nostdinc -w
# and prints the SHA-256 of the sorted list "<lang> <test> <sha256 of the assembly | FAIL>". Tests that do not compile
# (no headers, C-only constructs in C++, compiler errors) count as FAIL; that is deterministic too. Compare the line
# with fingerprints.txt. JOBS (default 2) compiles in parallel. Uses no game material.
set -eu
[ $# -ge 1 ] || { echo "usage: sh fingerprint.sh INSTALL_DIR [gcc-4.0.4.tar.bz2]" >&2; exit 2; }
INST=$(cd "$1" && pwd)
ROOT=${LBP_GCC4_ROOT:-$HOME/lbp-gcc4}
TARBALL=${2:-${LBP_GCC4_DL:-$ROOT/dl}/gcc-4.0.4.tar.bz2}
JOBS=${JOBS:-2}
GCC=$INST/bin/psp-gcc
FLAGS="-Os -G0 -fno-merge-constants -mpreferred-stack-boundary=4 -nostdinc -w"
[ -x "$GCC" ] || { echo "no $GCC" >&2; exit 2; }
echo "f3fde051c96d2fc084f6f4d6114ce4c1a079fcd1247d947d50a3d1641acafc47  $TARBALL" | sha256sum -c --quiet \
  || { echo "$TARBALL is not the verified gcc-4.0.4.tar.bz2" >&2; exit 2; }
LC_ALL=C; export LC_ALL
unset GCC_EXEC_PREFIX COMPILER_PATH CPATH C_INCLUDE_PATH CPLUS_INCLUDE_PATH 2>/dev/null || true
T=$(mktemp -d); trap 'rm -rf "$T"' EXIT INT TERM
tar --no-same-owner -xjf "$TARBALL" -C "$T" --wildcards 'gcc-4.0.4/gcc/testsuite/gcc.c-torture/compile/*.c'
cd "$T/gcc-4.0.4/gcc/testsuite/gcc.c-torture/compile"
mkdir "$T/out"
export GCC FLAGS T
ls -- *.c | sort | xargs -P "$JOBS" -n 1 sh -c '
  for lang in c c++; do
    o="$T/out/$1.$lang.s"
    if "$GCC" -x "$lang" -S $FLAGS -o "$o" "$1" > /dev/null 2>&1; then
      echo "$lang $1 $(sha256sum < "$o" | cut -c1-64)"
    else
      echo "$lang $1 FAIL"
    fi
  done' sh > "$T/list.unsorted"
sort "$T/list.unsorted" > "$T/list"
[ -n "${FINGERPRINT_LIST:-}" ] && cp "$T/list" "$FINGERPRINT_LIST"
n=$(wc -l < "$T/list"); fail=$(grep -c ' FAIL$' "$T/list" || true)
echo "FINGERPRINT $(basename "$INST") $(sha256sum < "$T/list" | cut -c1-64) compiled=$((n - fail)) failed=$fail"
