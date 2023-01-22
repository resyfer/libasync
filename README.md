# libasync

A wrapper around [libtpool](https://github.com/resyfer/libtpool) to help write
asynchronous code. Easy to use as well. For instructions on basic
usage, visit the [examples](/examples). For installation, please go
[here](#installation). For documentation, please visit
[here](https://libasync-doxygen.netlify.app/).

## Installation

Make sure to have [make](https://www.gnu.org/software/make/),
[gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/)
installed.

Then, make sure all the following dependencies are installed:
- [libtpool](https://github.com/resyfer/libtpool)
- [libqueue](https://github.com/resyfer/libqueue)
- [libcol](https://github.com/resyfer/libcol)

Then install the library:

```bash
git clone https://github.com/resyfer/libasync.git
cd libasync
make install
cd ..
rm -rf libasync
```

Provide the password when prompted.

## Development

Update makefile variable `MODE` to be:

```sh
MODE:=dev
```

and then:

```sh
make run # to run the example
# or
make test # to run the tests
```