# OpenCV test project

1. cross compile opencv as mentioned in the main readme.md
1. cmake

## toolchain
`toolchain-aarch64.cmake` should cover the necessary cross-compilation setup. `CMAKE_TOOLCHAIN_FILE`
**must** be defined either when calling `cmake` or before the `project()` directive inside the cmake.

## clangd
clangd will not automatically scan the correct system headers, despite reading compile_commands.json.
the query driver has to be changed to the new compiler: `--query-driver=/usr/bin/aarch64-linux-gnu-g++-9`