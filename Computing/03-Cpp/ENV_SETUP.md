# C++ 本地环境配置：VSCode / CLion

根据是否已经完成 VSCode 配置，选择下面的一条路径。两条路径均使用 C++17，并以运行 Hello World 为完成标准。课堂继续使用教师提供的 CPP-Classroom。

[English](./ENV_SETUP_en.md) · [完整离线 PDF](./ENV_SETUP.pdf) · [Hello World 源码](./Setup/hello.cpp)

## 方法一：已有 VSCode

保留现有 VSCode 配置，按系统补齐编译器：

- **Windows**：参考[配置视频](https://www.bilibili.com/video/BV1WnA9zJE72/)及指南中的 MSYS2 安装和 PATH 配置步骤。
- **macOS**：执行 `xcode-select --install`，安装 Xcode Command Line Tools。`g++` 调用 Apple Clang，可用于本课程的 C++17 程序。
- **Linux**：先执行 `g++ -v`；已有编译器则直接使用，缺少时按发行版安装。指南提供 Ubuntu/Debian 和 Fedora 命令。

**完成标准：在 VSCode 集成终端（Terminal）中执行 `g++ -v`，再用 `g++ -std=c++17` 编译并运行 Hello World。**

[VSCode 中文指南](./Setup/VSCode本地环境配置_zh.md) · [中文 PDF](./Setup/VSCode本地环境配置_zh.pdf) · [English guide](./Setup/VSCode本地环境配置_en.md) · [English PDF](./Setup/VSCode本地环境配置_en.pdf)

## 方法二：尚未配置 VSCode

沿用原来的 **CLion + 学校邮箱申请的 Student Pack 学生授权**方案。按指南完成申请、安装和激活；Windows 使用 Bundled MinGW，macOS 使用 Xcode Command Line Tools 提供的 Apple Clang。

新建 C++ Executable 项目，语言标准选择 C++17，将附带的 `hello.cpp` 复制到 `main.cpp`，点击 Run。

**完成标准：在 CLion 的 Run 窗口看到 `Hello World`。**

[CLion 中文指南](./Setup/CLion本地环境配置_zh.md) · [中文 PDF](./Setup/CLion本地环境配置_zh.pdf) · [English guide](./Setup/CLion本地环境配置_en.md) · [English PDF](./Setup/CLion本地环境配置_en.pdf)

Linux/Ubuntu 使用 CLion 的同学可以继续使用 Linux 课程环境，执行 `sudo apt update`、`sudo apt install build-essential gdb cmake` 安装工具链，再用 CLion 打开 [CMake 本地演示](./Lesson-1/CMakeIntro/README.md) 所在目录。

完整离线 PDF 依次包含本页、VSCode 指南和 CLion 指南。

[返回 C++ 课程](./README.md)
