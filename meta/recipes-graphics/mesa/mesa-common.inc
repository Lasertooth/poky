SUMMARY = "A free implementation of the OpenGL API"
DESCRIPTION = "Mesa is an open-source implementation of the OpenGL specification - \
a system for rendering interactive 3D graphics.  \
A variety of device drivers allows Mesa to be used in many different environments \
ranging from software emulation to complete hardware acceleration for modern GPUs. \
Mesa is used as part of the overall Direct Rendering Infrastructure and X.org \
environment."

HOMEPAGE = "http://mesa3d.org"
BUGTRACKER = "https://bugs.freedesktop.org"
SECTION = "x11"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://docs/license.html;md5=03ccdc4c379c4289aecfb8892c546f67"

INC_PR = "r0"
PE = "2"


PROTO_DEPS = "xf86driproto glproto"
LIB_DEPS += "${@base_contains('DISTRO_FEATURES', 'x11', \
	      'virtual/libx11 libxext libxxf86vm libxdamage libxfixes', '', d)}"

DEPENDS = "libxml2-native makedepend-native python-native flex-native bison-native ${LIB_DEPS}"
DEPENDS += "${@base_contains('DISTRO_FEATURES', 'x11', '${PROTO_DEPS}', '', d)}"

PROVIDES = "virtual/libgl virtual/libgles2"

# for mesa-dri and mesa-xlib
FILESEXTRAPATHS_append := "${THISDIR}/mesa:"

inherit autotools pkgconfig

EXTRA_OECONF = "--enable-glu \
                --disable-glw \
                --disable-glut"
EXTRA_OECONF += "${@base_contains('DISTRO_FEATURES', 'x11', '--enable-glx-tls', '--disable-glx', d)}"

# Multiple virtual/gl providers being built breaks staging
EXCLUDE_FROM_WORLD = "1"

# ie mesa-dri could be empty and mesa-dri-dev RDEPENDS on it
ALLOW_EMPTY_${PN} = "1"

PACKAGES =+ "libegl libegl-dev libegl-dbg libglu libglu-dev libosmesa libosmesa-dev libgl libgl-dev libgles2 libgles2-dev libgbm libgbm-dev libwayland-egl libwayland-egl-dev"
FILES_libegl = "${libdir}/libEGL.so.* ${libdir}/egl/*.so"
FILES_libgl = "${libdir}/libGL.so.*"
FILES_libgles2 = "${libdir}/libGLESv2.so.*"
FILES_libglu = "${libdir}/libGLU.so.*"
FILES_libosmesa = "${libdir}/libOSMesa.so.*"
FILES_libgbm = "${libdir}/libgbm.so.*"
FILES_libwayland-egl = "${libdir}/libwayland-egl.so.*"

FILES_libegl-dev = "${libdir}/libEGL.* ${includedir}/EGL ${includedir}/KHR"
FILES_libgl-dev = "${libdir}/libGL.* ${includedir}/GL ${libdir}/pkgconfig/gl.pc"
FILES_libgles2-dev = "${libdir}/libGLESv2.* ${includedir}/GLES2 ${libdir}/pkgconfig/glesv2.pc"
FILES_libglu-dev = "${libdir}/libGLU.* ${includedir}/GL/glu*.h"
FILES_libosmesa-dev = "${libdir}/libOSMesa.* ${includedir}/osmesa.h"
FILES_libgbm-dev = "${libdir}/libgbm.* ${includedir}/gbm.h ${libdir}/pkgconfig/gbm.pc"
FILES_libwayland-egl-dev = "${libdir}/libwayland-egl.* ${libdir}/pkgconfig/wayland-egl.pc"

FILES_${PN}-dbg += "${libdir}/dri/.debug/*"
FILES_libegl-dbg += "${libdir}/egl/.debug/*"
