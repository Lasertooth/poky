SUMMARY = "Generic XKB keymap library"

DESCRIPTION = "libxkbcommon is a keymap compiler and support library which \
processes a reduced subset of keymaps as defined by the XKB specification."

LICENSE = "MIT & MIT-style"

require xorg-lib-common.inc

PROTOCOLS = "xproto kbproto"
DEPENDS = "flex-native bison-native ${PROTOCOLS}"

LIC_FILES_CHKSUM = "file://COPYING;md5=469a86f811ec5d6bba592811c3005a2a"

SRCREV = "9bd55b55f8044ab105097af3b59db81f01db6c1a"
PV = "0.1.0+git${SRCPV}"
PR = "r0"

SRC_URI = "git://anongit.freedesktop.org/xorg/lib/libxkbcommon;protocol=git"
S = "${WORKDIR}/git"
