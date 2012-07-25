inherit autotools pkgconfig

SUMMARY = "Weston, a Wayland compositor"

DESCRIPTION = "Weston is the reference implementation of a Wayland compositor"

HOMEPAGE = "http://wayland.freedesktop.org"
SECTION = "wayland/base"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=275efac2559a224527bd4fd593d38466"


DEPENDS = "virtual/libgles2 wayland libxkbcommon gdk-pixbuf udev drm pixman cairo glib-2.0 mtdev jpeg"

EXTRA_OECONF = "--disable-wcap-tools --disable-xwayland --disable-x11-compositor --disable-weston-launch"

SRC_URI = "git://anongit.freedesktop.org/wayland/weston;protocol=git \
           file://0001-tests-Use-pkg-config-to-find-setbacklight-CFLAGS-and.patch \
	  "
S = "${WORKDIR}/git"

SRCREV = "d1936b9e2b352e93ace1b3609740ce4902b33a9e"
PV = "0.94.90+git${SRCPV}"
PR = "r0"
