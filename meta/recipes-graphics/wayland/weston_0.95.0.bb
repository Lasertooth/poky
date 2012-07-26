require weston.inc

SRC_URI = "http://wayland.freedesktop.org/releases/weston-0.95.0.tar.xz \
           file://0001-tests-Use-pkg-config-to-find-setbacklight-CFLAGS-and.patch \
	  "
SRC_URI[md5sum] = "77c87d8cc15e759ff512f9584d37e8a8"
SRC_URI[sha256sum] = "48244bdff173f8d57b15df1b43497b5a89d20740923f7d53cf11975a7890de15"

PR = "r0"

