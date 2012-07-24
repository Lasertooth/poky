PROTO_DEPS += "dri2proto"
LIB_DEPS += "libdrm expat udev"

LIB_DEPS +="${@base_contains('DISTRO_FEATURES', 'wayland', 'wayland', '', d)}"

# most of our targets do not have DRI so will use mesa-xlib
DEFAULT_PREFERENCE = "-1"

DRIDRIVERS = "swrast"
DRIDRIVERS_append_x86 = ",i915,i965"
DRIDRIVERS_append_x86-64 = ",i915,i965"

EGL_PLATFORMS  = "drm"
EGL_PLATFORMS .="${@base_contains('DISTRO_FEATURES', 'x11', ',x11', '', d)}"
EGL_PLATFORMS .="${@base_contains('DISTRO_FEATURES', 'wayland', ',wayland', '', d)}"

EXTRA_OECONF += "--disable-gallium --without-gallium-drivers"
EXTRA_OECONF += "--enable-dri --with-dri-drivers=${DRIDRIVERS}"
EXTRA_OECONF += "${@base_contains('DISTRO_FEATURES', 'opengles2', '--enable-gles2', '', d)}"
EXTRA_OECONF += "--enable-egl --with-egl-platforms=${EGL_PLATFORMS} --enable-gbm --enable-shared-glapi"

python populate_packages_prepend() {
	import os.path

	dri_drivers_root = os.path.join(d.getVar('libdir', True), "dri")

	do_split_packages(d, dri_drivers_root, '^(.*)_dri\.so$', 'mesa-dri-driver-%s', 'Mesa %s DRI driver', extra_depends='')
}

PACKAGES_DYNAMIC = "mesa-dri-driver-*"

FILES_${PN}-dbg += "${libdir}/dri/.debug/*"

