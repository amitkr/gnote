ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = 

INTLTOOL_FILES = intltool-extract.in \
                 intltool-merge.in \
                 intltool-update.in

DISTCLEANFILES = intltool-extract \
                 intltool-merge \
                 intltool-update \
                 po/.intltool-merge-cache

SUBDIRS = data src po help

DISTCHECK_CONFIGURE_FLAGS = --disable-schemas-install --disable-scrollkeeper

# Ignore scrollkeeper issues for now.  @#*$& scrollkeeper (from Evince)

