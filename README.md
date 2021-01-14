# R-Pi Developement

# Cross Compilation
use docker image.

## compilers
use the compilers in the docker image:
```bash
aarch64-linux-gnu-g++-9
aarch64-linux-gnu-gcc-9
```

## cmake
if not using multiarch, `CMAKE_FIND_ROOT_PATH` variable needs to be set to where there's an exact copy of the root filesystem of the target device.
```bash
cmake -DCMAKE_AR=aarch64-linux-gnu-ar -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc-9 -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++-9 ..
```
