# Top-level Makefile.am
#
# (c) Reuben Thomas 2011-2018
#
# The package is distributed under the MIT/X11 License.
#
# THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
# RISK.

SUBDIRS = src tests

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = m4/gnulib-cache.m4 README.md

release: distcheck
	git diff --exit-code && \
	git tag -a -m "Release tag" "v$(VERSION)" && \
	git push && git push --tags && \
	woger github \
		package=$(PACKAGE) \
		version=$(VERSION) \
		dist_type=tar.gz
