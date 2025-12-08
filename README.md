# C++ Template

## TODO
- Create an optimized prod method for docker and make scripts (eg O2 optimizations)

## Mobile (Android) IDE
- Download the app: `CxStudio`
- Open this repo as a `Project`
- Open the file `src/main.cpp`
- Run the program

## Build and Run in Debug Mode
1. Run the Docker Container
- If on Windows, make sure to launch `Docker Desktop` first and use `WSL`

```
./script/docker.sh -d
```

2. Run the cmake workflow in debug mode to build

```
./script/make.sh -d
```

3. Run the executable

```
./build/src/main.exe
```

## Running with GTest
- Steps are similar to the `Build and Run in Debug Mode` instructions

- Run the cmake workflow in test mode

```
./script/make.sh -t
```

- Run test executable

```
./build/test/main-test.exe
```

## Help Commands
- The `-h` or `--help` flag can be used on bash files within `scripts` directory

```
./script/docker.bat -h
```
```
./script/make.bat -h
```
