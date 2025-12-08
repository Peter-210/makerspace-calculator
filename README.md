# C++ Template

## TODO
- Create a linker that places everything in src into one file
- Modify script/make.sh to run gtest with -t flag
  - Must run test first then src. Else clean -c before running -t

## Build and Run
1. Run the Docker Container
- If on Windows, make sure to launch `Docker Desktop` first

```
./script/docker.sh -p
```

2. Run the cmake workflow to build

```
./script/make.sh -d
```

3. Run the executable

```
./build/src/main.exe
```

## Build and Run with GTest
1. Enable GTest within `CMakeLists.txt`

```
// Replace the following line:
option(ENABLE_TESTS "Enable GoogleTest For Testing" OFF)

// With the provided line below:
option(ENABLE_TESTS "Enable GoogleTest For Testing" ON)
```

2. Follow the `Build and Run` steps 1 and 2
    - Run Docker Container
    - Run CMake Workflow

3. Run the test executable

```
./build/test/main-test.exe
```

## Help Commands
- The `-h` or `--help` flag can be used on bash files within `scripts` directory

```
./script/make.bat -h
```
