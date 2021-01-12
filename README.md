# R-Pi Developement

## Cross Compilation
install the cross compiler:

```bash
sudo apt install crossbuild-essential-arm64
```
use the compilers :
```bash
aarch64-linux-gnu-g++-9
aarch64-linux-gnu-gcc-9
```
cmake ? probably also need to set the `CMAKE_FIND_ROOT_PATH` variable to a path where there's an exact copy of the root filesystem of the target device
```bash
cmake -DCMAKE_AR=aarch64-linux-gnu-ar -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc-9 -DCMAKE_CXX_COMPILER=aarch64-linux-gnu-g++-9 ..
```
