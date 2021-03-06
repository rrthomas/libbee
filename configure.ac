# configure.ac for libbee
# Process this file with autoconf to produce a configure script
#
# (c) Reuben Thomas 2011-2022
#
# The package is distributed under the MIT/X11 License.
#
# THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
# RISK.

AC_INIT(libbee, 1.0, rrt@sc3d.org)
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Check for programs
AC_PROG_CC_C99
gl_EARLY
AM_PROG_AR
LT_INIT

# Optimization
AX_CC_MAXOPT

# Extra warnings with GCC
AC_ARG_ENABLE([gcc-warnings],
  [AS_HELP_STRING([--disable-gcc-warnings],
                  [turn off lots of GCC warnings])],
  [case $enableval in
     yes|no) ;;
     *)      AC_MSG_ERROR([bad value $enableval for gcc-warnings option]) ;;
   esac
   gl_gcc_warnings=$enableval],
  [gl_gcc_warnings=yes]
)
if test "$gl_gcc_warnings" = yes; then
  # Set up the list of undesired warnings.
  nw=
  nw="$nw -Wsystem-headers"   # Don’t let system headers trigger warnings

  gl_MANYWARN_ALL_GCC([warnings])

  # Enable all GCC warnings not in this list.
  gl_MANYWARN_COMPLEMENT([warnings], [$warnings], [$nw])
  for w in $warnings; do
    gl_WARN_ADD([$w])
  done

  # When compiling with GCC, prefer -isystem to -I when including system
  # include files, to avoid generating useless diagnostics for the files.
  ISYSTEM='-isystem '
else
  ISYSTEM='-I'
fi
AC_SUBST([ISYSTEM])

# Check for header files
AC_HEADER_STDC
gl_INIT

# Check features
AC_C_BIGENDIAN
AC_CHECK_SIZEOF([intptr_t])
SIZEOF_INTPTR_T=$ac_cv_sizeof_intptr_t
AC_SUBST([SIZEOF_INTPTR_T])
AX_C_ARITHMETIC_RSHIFT

# Generate output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
        Makefile
        src/Makefile
        tests/Makefile
])
AC_OUTPUT
