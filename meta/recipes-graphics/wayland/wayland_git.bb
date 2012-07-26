require wayland.inc

SRC_URI = "git://anongit.freedesktop.org/wayland/wayland;protocol=git"
S = "${WORKDIR}/git"

SRCREV = "f5ccd7a9e670e097ff9b5faae8a26b3af4bb7b60"
PV = "0.95.0+git${SRCPV}"
PR = "r0"
