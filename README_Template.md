# C++ Template

## Setup
1. Make sure to have `Docker` installed
    - If on Windows, use `WSL` with `Docker Desktop` (Make sure to use `Linux Containers`)
2. Give permission to execute helper script files: 
```
chmod u+x script/*
```
3. Make sure your project directory is formatted as such: `my-project-dir`
    - Then run `script/setup.sh`. This will set project directory to be the name used in docker

## Usage
- This project contains scripts that can run in different modes: 
    - `-p` (prod) - Minimal installed tools on docker and optimized code from the compiler
    - `-d` (dev/debug) - All tools installed for debugging the project (eg. GDB)
    - `-t` (test) - Used for unit testing with GTest

- To learn more about these modes, use the `-h` or `--help` flag for the following scripts:
```
./scripts/docker.sh -h
```
```
./scripts/make.sh -h
```

## Build and Run
- Refer to the [Usage](#usage) section of this guide for details on `modes`
- All modes follow a similar step with slight differences

### Build and Run (Prod Mode)
1. Run the Docker Container
```
./script/docker.sh -p
```

2. Run the cmake workflow to build
```
./script/make.sh -p
```

3. Run the executable
```
./build/src/main
```

### Build and Run (Dev/Debug Mode)
1. Run the Docker Container
```
./script/docker.sh -d
```

2. Run the cmake workflow to build
```
./script/make.sh -d
```

3. Run the executable
```
gdb ./build/src/main
```

### Build and Run (Test Mode)
1. Run the Docker Container
```
./script/docker.sh -d
```

2. Run the cmake workflow to build
```
./script/make.sh -t
```

3. Run the executable
```
./build/test/main-test
```

## Troubleshooting
- For any missing dependencies in docker container, run the following to clean container then re-run the script with the proper flag mode (-p/d):
```
./script/docker.sh -c
```

- For any conflicts with docker container, run the following to clean container and image then re-run the script with the proper flag mode (-p/d):
    - The order is important. Clean container first, then image
```
./script/docker.sh -c
./script/docker.sh -i
```

- For CMake builds that are not updating to code changes, run the following to clean build then re-run the script with the proper flag mode (-p/d/t):
```
./script/make.sh -c
```

- For GTest lib files being corrupted, run the following to clean lib files then re-run the script with the proper flag mode (-t):
```
./script/make.sh -l
```

## TODO

### Working On
- GCC Flag `-Weffc++` throws errors for GTest
- Create a setup script for stuff like container naming and README project name
- One for project setup (README details) and the other for general setup (docker container and image names)
    - Automate filling in project name and details for README
    - Create custom container and image names

### Ignored
- Add volume (personal storage) to docker containers
- Use the container name change to create a prod and debug seperate containers
- Create an auto build for prod docker
