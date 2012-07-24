DEPENDS += "mesa-dri-glsl-native"

SRCREV = "27382c0f7ba2ae826531ba4c254741b2a9df1882"
PV = "8.1.0+git${SRCPV}"

LIC_FILES_CHKSUM = "file://docs/license.html;md5=3297a8331ba66df8f0c0d7844f90645e"
FILESEXTRAPATHS_prepend := "${THISDIR}/mesa-git:"

SRC_URI = "git://anongit.freedesktop.org/git/mesa/mesa;protocol=git \
           file://0001-Compile-with-uclibc.patch \
           file://0002-cross-compile.patch \
           file://0003-fix-for-x32.patch \
           "
S = "${WORKDIR}/git"

do_configure_prepend() {
  #check for python not python2, because python-native does not stage python2 binary/link
  sed -i 's/AC_CHECK_PROGS(\[PYTHON2\], \[python2 python\])/AC_CHECK_PROGS(\[PYTHON2\], \[python python\])/g' ${S}/configure.ac
  # We need builtin_compiler built for buildhost arch instead of target (is provided by mesa-dri-glsl-native)"
  sed -i "s#\./builtin_compiler#${STAGING_BINDIR_NATIVE}/glsl/builtin_compiler#g" ${S}/src/glsl/Makefile.am
}
