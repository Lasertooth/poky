require weston.inc

SRC_URI = "git://anongit.freedesktop.org/wayland/weston;protocol=git \
           file://0001-tests-Use-pkg-config-to-find-setbacklight-CFLAGS-and.patch \
	  "
S = "${WORKDIR}/git"

SRCREV = "e302b3ef77894cb9fd4113c873a5502efc9a8dd6"
PV = "0.95.0+git${SRCPV}"
PR = "r0"
