# Tests Makefile.am
#
# (c) Reuben Thomas 2011-2022
#
# The package is distributed under the MIT/X11 License.
#
# THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
# RISK.

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_builddir)/src $(WARN_CFLAGS)

LOG_COMPILER = $(srcdir)/run-test

LDADD = $(top_builddir)/src/libbee.la

check_PROGRAMS = $(TESTS)

TESTS = arithmetic comparison logic memory
TESTS_ENVIRONMENT = \
	export LIBTOOL=$(top_builddir)/libtool;

EXTRA_DIST = \
	run-test \
	tests.h
