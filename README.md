# libbee

by Reuben Thomas <rrt@sc3d.org>  
https://github.com/rrthomas/libbee  

libbee is a C library of functions for operations normally only available in
the language, such as integer arithmetic and bitwise operations.

It is written in plain ISO C99.

The package is distributed under the MIT/X11 license.

THIS PROGRAM IS PROVIDED AS IS, WITH NO WARRANTY. USE IS AT THE USER’S
RISK.


## Installation and compatibility

Bee should compile on any POSIX-1.2001-compatible system, and the main
source code `lib.c` on any ISO C99 system.

Reports on compatibility are welcomed.


### Building from a release tarball

To build from a release tarball, run

`./configure && make check`


### Building from git

The GNU autotools are required: automake, autoconf and libtool.
[Gnulib](https://www.gnu.org/software/gnulib/) is also used, with a
third-party `bootstrap` module; these are installed automatically.

To build from a Git repository, first run

```
./bootstrap
```

Then see "Building from source" above.


## Documentation

Sorry, there’s only the source code at present.


## Bugs and comments

Please send bug reports (preferably as [GitHub issues](https://github.com/rrthomas/bee/issues))
and comments. I’m especially interested to know of portability bugs.
