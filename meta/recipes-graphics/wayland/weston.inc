inherit autotools pkgconfig

SUMMARY = "Weston, a Wayland compositor"
DESCRIPTION = "Weston is the reference implementation of a Wayland compositor"
HOMEPAGE = "http://wayland.freedesktop.org"
SECTION = "wayland/base"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=275efac2559a224527bd4fd593d38466"

DEPENDS = "virtual/libgles2 wayland libxkbcommon gdk-pixbuf udev drm pixman cairo glib-2.0 mtdev jpeg"

EXTRA_OECONF  = "--disable-wcap-tools --disable-xwayland --disable-x11-compositor --disable-weston-launch"
EXTRA_OECONF += "--disable-android-compositor"
