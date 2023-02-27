
# Extent

A package providing an object to represent a 2D boundary box around an object.
It's used by TotalPave's [QuadTree](https://github.com/totalpaveinc/quadtree) package
as well as [libtilegen](https://github.com/totalpaveinc/libtilegen)

## How to import

We recommend cloning this repo as a git submodule somewhere within your project.
Then using CMake's [add_subdirectory](https://cmake.org/cmake/help/latest/command/add_subdirectory.html)
directive so that it's included as part of your build system, building using
whatever toolchain you're using. Use the `tpgeomextent` name for linking.

## Releases

Releases are by tags only. We do not build prebuilt binaries for this package.
Tags can be used to pin to a specific version if desired.

# TotalPave Committers

This section is for TotalPave employees.

## How to make a release

1.  Open `CMakeLists.txt` and change the `VERSION` to match the version you intend
    to release. Follow [Semantic Versioning](https://semver.org/) rules.
2.  Commit the change.
3.  Tag the commit `v<x.y.z>`.
4.  Push the commit & tags (`git push && git push --tags`)
