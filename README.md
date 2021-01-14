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

## opencv
```bash
cmake -DCMAKE_BUILD_TYPE=RELEASE \
	-DCMAKE_TOOLCHAIN_FILE=../platforms/linux/aarch64-gnu.toolchain.cmake \
	-DBUILD_TESTS=OFF \
	-DBUILD_DOCS=OFF \
	-DPYTHON3_INCLUDE_PATH=/usr/include/python3.8 \
	-DPYTHON3_LIBRARIES=/usr/lib/aarch64-linux-gnu/libpython3.8.so 
	-DPYTHON3_NUMPY_INCLUDE_DIRS=/usr/lib/python3/dist-packages/numpy/core/include \
	-DBUILD_OPENCV_PYTHON3=ON \
	-DBUILD_EXAMPLES=OFF ..
```
