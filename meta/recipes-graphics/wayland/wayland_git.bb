inherit autotools pkgconfig

SUMMARY = "Wayland, a protocol between a compositor and clients"

DESCRIPTION = "Wayland is a protocol for a compositor to talk to its clients \
as well as a C library implementation of that protocol. The compositor can be \
a standalone display server running on Linux kernel modesetting and evdev \
input devices, an X application, or a wayland client itself. The clients can \
be traditional applications, X servers (rootless or fullscreen) or other \
display servers."

HOMEPAGE = "http://wayland.freedesktop.org"
SECTION = "wayland/base"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=1d4476a7d98dd5691c53d4d43a510c72"

# needs wayland-native for the wayland-scanner utility
BBCLASSEXTEND = "native"

DEPENDS_virtclass-native = "expat-native"
DEPENDS = "expat wayland-native"

EXTRA_OECONF_virtclass-native = "--disable-documentation"
EXTRA_OECONF = "--disable-documentation --disable-scanner"

SRC_URI = "git://anongit.freedesktop.org/wayland/wayland;protocol=git"
S = "${WORKDIR}/git"

SRCREV = "2e79c4877fc4f402297e9d685b5eb2c41d7dd814"
PV = "0.94.90+git${SRCPV}"
PR = "r0"
