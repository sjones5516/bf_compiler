# bf_compiler

The goal of this project is to create a Brainfuck (BF) compiler that can output x86_64 assemblable by NASM.
Since BF is a really simple language, more focus can go towards the compiler structure itself.
This is a work in progress.

# Building

To clone and build with Ninja:

```shell
cmake -S . -B ./build -G "Ninja Multi-Config"
```

To build the main executable:

```shell
cmake --build ./build
```

You can also specify the build configuration as Debug, Release, MinSizeRel, RelWithDebInfo:

```shell
cmake --build ./build --config=Release
```

To include the GTest suite set the `BUILD_TESTING` flag (default is OFF):

```shell
cmake -S . -B ./build -G "Ninja Multi-Config" -D BUILD_TESTING=ON
```

To build and execute the test target, ensure the GTest suite is included and build the `BF_test` target:

``` shell
cmake --build ./build --target=BF_test
ctest
```
