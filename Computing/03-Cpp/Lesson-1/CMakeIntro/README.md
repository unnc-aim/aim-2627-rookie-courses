# CMake 本地构建演示

本项目使用第一课 S01 的完整程序，配合讲义 1.1 的 CMake 介绍。`CMakeLists.txt` 与 `S01.cpp` 放在同一目录。

在此目录打开终端，执行：

```shell
cmake -S . -B build
cmake --build build
```

macOS / Linux 常见单配置构建完成后运行：

```shell
./build/S01
```

Windows 单配置构建常见运行命令为 `.\build\S01.exe`。Visual Studio 等多配置生成器可以先执行 `cmake --build build --config Debug`，再运行 `.\build\Debug\S01.exe`。具体输出路径以所用生成器和配置为准。

在 CPP-Classroom 中练习时继续使用单份 `.cpp`，不把 CMakeLists.txt 或终端命令粘贴进代码区。

[返回第一课](../README.md)
