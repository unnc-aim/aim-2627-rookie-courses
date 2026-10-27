# Local C++ setup: VSCode / CLion

Choose a path based on whether VSCode is already configured. Both paths use C++17 and finish by running Hello World. Classes continue to use the instructor-provided CPP-Classroom.

[中文](./ENV_SETUP.md) · [Complete offline PDF](./ENV_SETUP_en.pdf) · [Hello World source](./Setup/hello.cpp)

## Path 1: VSCode is ready

Keep your existing VSCode settings and prepare the compiler for your operating system:

- **Windows:** Follow the [reference video](https://www.bilibili.com/video/BV1WnA9zJE72/) and the guide's MSYS2 installation and PATH configuration steps.
- **macOS:** Run `xcode-select --install` to install Xcode Command Line Tools. The `g++` command invokes Apple Clang, which supports the course's C++17 programs.
- **Linux:** Run `g++ -v` first. Use an existing compiler or install one for your distribution if needed. The guide includes Ubuntu/Debian and Fedora commands.

**Completion: run `g++ -v`, then compile Hello World with `g++ -std=c++17` and run it in the VSCode integrated terminal.**

[VSCode Chinese guide](./Setup/VSCode本地环境配置_zh.md) · [Chinese PDF](./Setup/VSCode本地环境配置_zh.pdf) · [English guide](./Setup/VSCode本地环境配置_en.md) · [English PDF](./Setup/VSCode本地环境配置_en.pdf)

## Path 2: VSCode is not configured

Follow the existing **CLion setup with a Student Pack license applied for using your university email**. Complete the application, installation, and activation. Use bundled MinGW on Windows or Apple Clang from Xcode Command Line Tools on macOS.

Create a C++ Executable project, select C++17, copy the accompanying `hello.cpp` into `main.cpp`, and click Run.

**Completion: confirm `Hello World` in the CLion Run window.**

[CLion Chinese guide](./Setup/CLion本地环境配置_zh.md) · [Chinese PDF](./Setup/CLion本地环境配置_zh.pdf) · [English guide](./Setup/CLion本地环境配置_en.md) · [English PDF](./Setup/CLion本地环境配置_en.pdf)

For CLion on Linux/Ubuntu, continue using your Linux course environment. Run `sudo apt update` and `sudo apt install build-essential gdb cmake` to install the toolchain, then open this module's CMake project in CLion. See the module README for other build options.

The complete offline PDF contains this page, the VSCode guide, and the CLion guide, in that order.

[Back to the C++ module](./README.md)
