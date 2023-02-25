
# Overview

Extent Package used by Quad Tree and libtilegen.

Provides a class to represent an extent of a geographic item.

## Building for localhost

git clone/checkout. Switch to the desired version by tag.

```
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Notes for Libtilegen / Mobile binaries

If the package is to be consumed for multiple architectures,
installing this package as a git submodule and using CMAKE `add_subdirectory` directive can be used to build using the current toolchains for the target architecture.

Use the `tpgeomextent` target for linking.

## Building tests

Tests are automatically built if `CMAKE_BUILD_TYPE` is `Debug`.
Run the executable to run the tests.

Version 3 of [Catch2](https://github.com/catchorg/Catch2) is required to be installed on the host machine.
