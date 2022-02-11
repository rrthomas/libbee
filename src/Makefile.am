# Source Makefile.am
#
# (c) Reuben Thomas 2011-2022
#
# The package is distributed under the MIT/X11 License.
#
# THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
# RISK.

AM_CPPFLAGS = $(WARN_CFLAGS)

lib_LTLIBRARIES = libbee.la
libbee_la_SOURCES = lib.c
nodist_libbee_la_SOURCES = private.h

nodist_pkginclude_HEADERS = libbee.h

CLOC = cloc --force-lang="C",h

loc:
	$(CLOC) $(libbee_la_SOURCES) $(bee_SOURCES)
