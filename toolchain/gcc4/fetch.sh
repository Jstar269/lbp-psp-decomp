#!/bin/sh
# SPDX-License-Identifier: GPL-3.0-or-later
# Download (when absent) and verify the sources the GCC 4.x build kit builds from: three GNU GCC release tarballs
# with their detached signatures and two pspdev/ps2dev psptoolchain Allegrex patches.
#
#   sh fetch.sh [DL_DIR]
#
# DL_DIR defaults to $LBP_GCC4_DL, else $LBP_GCC4_ROOT/dl, else $HOME/lbp-gcc4/dl. Files already present are not
# downloaded again (put copies there to work offline). Every file is checked against sources.sha256, and every GNU
# tarball's .sig with gpgv against the GNU keyring: GNU_KEYRING=<file> names a local keyring, otherwise
# https://ftp.gnu.org/gnu/gnu-keyring.gpg is fetched into DL_DIR. GNU_MIRROR replaces https://ftp.gnu.org/gnu.
# Prints FETCH_OK and exits 0 only when everything verifies.
set -eu
HERE=$(cd "$(dirname "$0")" && pwd)
ROOT=${LBP_GCC4_ROOT:-$HOME/lbp-gcc4}
DL=${1:-${LBP_GCC4_DL:-$ROOT/dl}}
GNU=${GNU_MIRROR:-https://ftp.gnu.org/gnu}
PSPTC=https://raw.githubusercontent.com/badboy/ps2dev-psptoolchain

mkdir -p "$DL"
DL=$(cd "$DL" && pwd)
cd "$DL"

get() {  # get URL FILE
  [ -s "$2" ] && return 0
  echo "fetch $1"
  if command -v wget >/dev/null 2>&1; then wget -q -O "$2.part" "$1"; else curl -fsSL -o "$2.part" "$1"; fi
  mv "$2.part" "$2"
}

for v in 4.0.2 4.0.4 4.1.0; do
  get "$GNU/gcc/gcc-$v/gcc-$v.tar.bz2" "gcc-$v.tar.bz2"
  get "$GNU/gcc/gcc-$v/gcc-$v.tar.bz2.sig" "gcc-$v.tar.bz2.sig"
done
# ps2dev.org psptoolchain (svn mirror on GitHub): the GCC 4.0.2 patch at commit 65aaa94632 (2007-01-23, PSPDEV
# 20051022 plus -mpreferred-stack-boundary) and the GCC 4.1.0 patch at commit 7be303fec4 (PSPDEV 20060507, 2008).
get "$PSPTC/65aaa94632/gcc-4.0.2.patch" 65aaa94632-gcc-4.0.2.patch
get "$PSPTC/7be303fec4/patches/gcc-4.1.0-PSP.patch" 7be303fec4-gcc-4.1.0-PSP.patch

sha256sum -c "$HERE/sources.sha256"

KEYRING=${GNU_KEYRING:-}
if [ -z "$KEYRING" ]; then
  get "$GNU/gnu-keyring.gpg" gnu-keyring.gpg
  KEYRING=$DL/gnu-keyring.gpg
fi
case $KEYRING in /*) ;; *) KEYRING=$(pwd)/$KEYRING ;; esac   # gpgv reads a bare name from GNUPGHOME
for v in 4.0.2 4.0.4 4.1.0; do
  if ! gpgv --keyring "$KEYRING" "gcc-$v.tar.bz2.sig" "gcc-$v.tar.bz2" > "gpgv-$v.log" 2>&1; then
    cat "gpgv-$v.log"; echo "FETCH_FAIL signature gcc-$v.tar.bz2"; exit 1
  fi
  echo "SIG_OK gcc-$v.tar.bz2 $(grep -o 'Good signature from "[^"]*"' "gpgv-$v.log")"
done
echo "FETCH_OK $DL"
