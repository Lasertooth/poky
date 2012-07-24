require mesa-dri-glsl-native.inc

LIC_FILES_CHKSUM = "file://docs/license.html;md5=3297a8331ba66df8f0c0d7844f90645e"

SRCREV = "27382c0f7ba2ae826531ba4c254741b2a9df1882"
PV = "8.1.0+git${SRCPV}"
DEFAULT_PREFERENCE = "-1"

SRC_URI = "git://anongit.freedesktop.org/git/mesa/mesa;protocol=git"
S = "${WORKDIR}/git"

# Let's compile a minimum EGL/NULL GLES2 without a single dri driver to get the
# native utility that generates some C files.
EXTRA_OECONF  = "--disable-glu --disable-glx --disable-gallium-egl --without-gallium-drivers"
EXTRA_OECONF += "--disable-dri --enable-gles2"
EXTRA_OECONF += "--enable-egl --with-egl-platforms=null"

inherit native autotools

do_install() {
	install -d ${D}/${bindir}/glsl
	install -m 755 ${S}/src/glsl/builtin_compiler ${D}/${bindir}/glsl/builtin_compiler
	install -m 755 ${S}/src/glsl/glsl_compiler ${D}/${bindir}/glsl/glsl_compiler
}
