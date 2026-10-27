# C++ 编程基础课程

## 模块概述

C++ 编程模块包含 2 节课程，承接 Python 基础，学习 C++17 的语法、函数和面向对象编程，为后续 ROS2、视觉、导航和控制工程做准备。

本目录整理自本地已有 C++ 培训材料，保留双语讲义、课件与例题正文，沿用原课的基础语法与 Band 乐队模型主线。

## 学习目标

通过本模块学习，学员将能够：

- 理解源码、编译与运行的关系
- 使用基本类型、输入输出、运算符、条件和循环
- 操作数组、`std::array`、`std::string` 和 `std::vector`
- 理解函数、值传递、引用、地址与指针
- 使用类、构造函数、封装、继承、`protected` 和 `this`
- 阅读并修改小型 C++ 程序，检查边界与编译诊断

## 环境配置

课前按已有环境选择两条路径之一：**已有 VSCode** 的同学补齐编译器，在集成终端中执行 `g++ -v` 并编译运行 Hello World；**尚未配置 VSCode** 的同学沿用 CLion + Student Pack 学生授权方案。macOS 使用 `xcode-select --install`，Linux 先检查 g++、缺少时再安装。课堂使用教师提供的 CPP-Classroom。

- 配置指南：[中文](./ENV_SETUP.md) · [English](./ENV_SETUP_en.md)
- 完整离线指南（包含两种方案）：[中文 PDF](./ENV_SETUP.pdf) · [English PDF](./ENV_SETUP_en.pdf)
- VSCode 指南：[中文](./Setup/VSCode本地环境配置_zh.md) · [PDF](./Setup/VSCode本地环境配置_zh.pdf) · [English](./Setup/VSCode本地环境配置_en.md) · [PDF](./Setup/VSCode本地环境配置_en.pdf)
- CLion 指南：[中文](./Setup/CLion本地环境配置_zh.md) · [PDF](./Setup/CLion本地环境配置_zh.pdf) · [English](./Setup/CLion本地环境配置_en.md) · [PDF](./Setup/CLion本地环境配置_en.pdf)
- 验证程序：[hello.cpp](./Setup/hello.cpp)
- 课堂操作：[CPP-Classroom 使用说明](./Classroom/README.md)

## 课程安排

### Lesson-1: 基础语法

**学习内容：**

- 从 Python 进入 C++：头文件、`main`、分号和语句块
- 命名空间、输入输出、基础类型与输出格式
- 运算符、条件和 `for` 循环
- 数组、`std::array` 与范围遍历
- 字符串的查、改、增、删
- 第一课整合与结构体预告

**课堂实践：** 输入输出、运算、数组和字符串实验；原课综合演示。

[课程说明](./Lesson-1/README.md) · [中文讲义](./Lesson-1/Lecture.md) · [English notes](./Lesson-1/Lecture_en.md)

### Lesson-2: 函数与面向对象

**学习内容：**

- `test_add`：参数、计算和返回值
- 引用、地址、指针及 `swap1` / `swap2` 交换实验
- 从 `struct` 到 `Band`，构造函数与初始化
- 实例、成员方法与 `std::vector<Band>`
- `MofoBand` 的继承与基类构造
- `protected`、`this` 与第二层派生
- 工程拓展：虚函数、对象切片与资源所有权

**课堂实践：** 乐队模型的创建、封装、成员修改与继承。

[课程说明](./Lesson-2/README.md) · [中文讲义](./Lesson-2/Lecture.md) · [English notes](./Lesson-2/Lecture_en.md)

## 技能要求

### 入门要求

- 完成 [Python 基础课程](../01-Python/README.md)
- 理解变量、条件、循环、函数和类的基本概念
- 完成 VSCode 或 CLion 路径的本地 Hello World 验收

### 完成后技能水平

- 能将已学 Python 基础概念迁移到 C++
- 能独立编译和运行单文件 C++17 程序
- 能解释值传递、引用和指针对调用者状态的影响
- 能阅读类与继承关系，为 [ROS2](../04-ROS2/README.md) 学习做准备

## 开发环境

- **语言标准**：C++17
- **本地编辑器 / IDE**：已有 VSCode 的同学继续使用 VSCode；尚未配置的同学使用 CLion（Student Pack 学生授权）
- **编译器**：Windows 的 VSCode 路径使用 MSYS2 g++，CLion 路径使用 Bundled MinGW；macOS 使用 Apple Clang；Linux 先检查 g++、缺少时再安装
- **课堂平台**：CPP-Classroom，每题一份完整 `.cpp`，保留唯一 `main`

讲义使用 Markdown，C++ 示例直接编译运行，无需安装 C++ Jupyter 内核。

## 学习资源

| 材料 | Lesson-1 | Lesson-2 |
| --- | --- | --- |
| 课程入口 | [基础语法](./Lesson-1/README.md) | [函数与面向对象](./Lesson-2/README.md) |
| 完整讲义 | [中文](./Lesson-1/Lecture.md) · [English](./Lesson-1/Lecture_en.md) | [中文](./Lesson-2/Lecture.md) · [English](./Lesson-2/Lecture_en.md) |
| 讲义 PDF | [中文](./Lesson-1/Lecture.pdf) · [English](./Lesson-1/Lecture_en.pdf) | [中文](./Lesson-2/Lecture.pdf) · [English](./Lesson-2/Lecture_en.pdf) |
| 课件 PDF | [中文](./Lesson-1/Slides.pdf) · [English](./Lesson-1/Slides_en.pdf) | [中文](./Lesson-2/Slides.pdf) · [English](./Lesson-2/Slides_en.pdf) |
| PowerPoint | [中文](./Lesson-1/Slides.pptx) · [English](./Lesson-1/Slides_en.pptx) | [中文](./Lesson-2/Slides.pptx) · [English](./Lesson-2/Slides_en.pptx) |
| Marp 源稿 | [中文](./Lesson-1/Slides.md) · [English](./Lesson-1/Slides_en.md) | [中文](./Lesson-2/Slides.md) · [English](./Lesson-2/Slides_en.md) |
| 在线放映 | [中文](./Lesson-1/Slides.html) · [English](./Lesson-1/Slides_en.html) | [中文](./Lesson-2/Slides.html) · [English](./Lesson-2/Slides_en.html) |
| 分章讲义 | [章节索引](./Lesson-1/Chapters/README.md) | [章节索引](./Lesson-2/Chapters/README.md) |
| 完整程序 | [正文实验与例题](./Lesson-1/Examples/README.md) | [正文实验与例题](./Lesson-2/Examples/README.md) |

- [120 道双语例题索引](./Exercises/README.md)：题目、样例、推导、边界与完整参考程序
- [cppreference](https://en.cppreference.com/w/cpp)：语言与标准库参考
- [LearnCpp](https://www.learncpp.com/)：C++ 入门教程

## 教学代码写法

本课程以 C++17 为语言上限。教学代码使用显式类型，标量采用等号初始化，普通对象采用圆括号构造；数组和聚合数据采用等号后的初始化列表。
