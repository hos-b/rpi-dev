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
if not using multiarch, `CMAKE_SYSROOT` variable needs to be set to where there's an exact copy of the root filesystem of the target device. cmake `find_*` commands will look in the sysroot, and the `CMAKE_FIND_ROOT_PATH` entries by default in all cases, as well as looking in the host system root prefix. `software/opencv-test/toolchain-aarch64.cmake` should cover both.

## opencv
```bash
cmake -DCMAKE_BUILD_TYPE=RELEASE \
	-DCMAKE_TOOLCHAIN_FILE=../platforms/linux/aarch64-gnu.toolchain.cmake \
	-DBUILD_TESTS=OFF \
	-DBUILD_DOCS=OFF \
	-DPYTHON3_INCLUDE_PATH=/usr/include/python3.8 \
	-DPYTHON3_LIBRARIES=/usr/lib/aarch64-linux-gnu/libpython3.8.so \
	-DPYTHON3_NUMPY_INCLUDE_DIRS=/usr/lib/python3/dist-packages/numpy/core/include \
	-DBUILD_OPENCV_PYTHON3=ON \
	-DBUILD_OPENCV_PYTHON2=OFF \
	-DENABLE_NEON=ON \
	-DBUILD_EXAMPLES=OFF ..
```

cannot enable VFPV3:
```
Required baseline optimization is not supported: VFPV3
(CPU_BASELINE_REQUIRE=;VFPV3;NEON)
```