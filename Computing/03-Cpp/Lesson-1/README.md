# C++ Lesson-1: 基础语法

## 课程信息

- **课时**：主课 3 小时，含演示、练习、讨论与 10 分钟休息；拓展另计
- **难度**：入门迁移
- **前置要求**：Python 基础；完成[本地环境配置（VSCode / CLion）](../ENV_SETUP.md)
- **语言标准**：C++17

## 学习目标

完成本节课后，学员将能够：

1. 区分编译失败与运行错误
2. 解释整数除法与浮点除法的区别
3. 正确读取不同类型的数据并设置输出精度
4. 用条件与循环处理数组，避免越界
5. 检查字符串查找失败并完成查改增删
6. 运行综合示例并解释每一步状态变化

## 本课主线

沿用现有讲义与原课程序的演示顺序。先预测程序行为，再运行、分析状态变化并检查边界。

| 顺序 | 现有章节 | 原课对象 |
| --- | --- | --- |
| 1 | 从 Python 进入 C++ 程序 | `头文件、main` |
| 2 | 命名空间与第一次输出 | `namespace_test、new_new` |
| 3 | 输入、变量与输出格式 | `input_int、input_variable` |
| 4 | 运算符的逐步计算 | `calculate` |
| 5 | 条件与 for 循环 | `if_and_for` |
| 6 | 数组、std::array 与范围遍历 | `score、score_new、shuzu` |
| 7 | 字符串的查、改、增、删 | `str_modern` |
| 8 | 第一课整合与结构体预告 | `综合程序与记录类型` |

## 课程大纲

### 1. 从 Python 进入 C++ 程序

分号、语句块、类型检查、编译诊断与退出状态。

### 2. 命名空间与第一次输出

std::、using 与同名冲突；cout、换行与刷新。

### 3. 输入、变量与输出格式

int、double、char、string；连续提取、输入失败、fixed 与 setprecision。

### 4. 运算符的逐步计算

取余与整数除法、转换时机、赋值与比较、逻辑、数学函数、自增自减。

### 5. 条件与 for 循环

互斥分支、循环初始化、继续条件与更新。

### 6. 数组、std::array 与范围遍历

部分初始化、元素赋值、下标边界、范围循环中的副本与原元素。

### 7. 字符串的查、改、增、删

沿用 mygo 示例；识别 std::string::npos，处理查找失败与分隔符。

### 8. 第一课整合与结构体预告

从平行变量过渡到一条记录；函数、引用与指针在第二课正式展开。

## 课堂材料

- **完整讲义**：[中文](./Lecture.md) · [English](./Lecture_en.md) · [中文 PDF](./Lecture.pdf) · [English PDF](./Lecture_en.pdf)
- **课件**：[中文 PDF](./Slides.pdf) · [English PDF](./Slides_en.pdf) · [中文 PPTX](./Slides.pptx) · [English PPTX](./Slides_en.pptx)
- **Marp 源稿**：[中文](./Slides.md) · [English](./Slides_en.md)
- **完整程序**：[正文实验与例题索引](./Examples/README.md) · [综合演示 Demo.cpp](./Demo.cpp)

## 实践项目

运行现有综合程序，依次观察输入输出、运算、分支、数组与字符串的状态变化。需要预填以下输入：

```text
8 4
3.14159 A mutsumi
0
```

## 课堂练习

按讲义章节选择配套例题，先预测输出，再运行并解释差异。[双语例题索引](../Exercises/README.md) 按实际课次和章节列出全部题目；S 系列中的函数、引用和指针题按原顺序安排到第二课。

## 课后作业

完成 [Assessment-01 学生模板](../Assessment-01/README.md)，要求与评分以 [中文题面](../Assessment-01/PROBLEM.md) / [English statement](../Assessment-01/PROBLEM_en.md) 为准。引用、指针、虚函数与所有权相关题目在第二课对应章节后完成。

## 学习检查点

- [ ] 能区分编译失败与运行错误
- [ ] 能解释整数除法与浮点除法的区别
- [ ] 能正确读取不同类型的数据并设置输出精度
- [ ] 能用条件与循环处理数组，避免越界
- [ ] 能检查字符串查找失败并完成查改增删
- [ ] 能运行综合示例并解释每一步状态变化

## 扩展阅读

- [C++ 语言参考](https://en.cppreference.com/w/cpp/language)
- [C++ 标准容器](https://en.cppreference.com/w/cpp/container)

[返回 C++ 模块](../README.md) · [下一课：函数与面向对象](../Lesson-2/README.md)

## 课堂放映与逐页提示

本课课件独立编排为 62 页，主课时间表按 180 分钟安排。采用讲解、预测、运行、逐步推导、练习与讲评交替的节奏。完整讲义用于查阅，整套例题用于加练。

[中文放映](Slides.html) · [English slideshow](Slides_en.html) · [中文逐页授课提示](TeachingGuide.md) · [English teaching guide](TeachingGuide_en.md)

PPTX 中的文字和代码可编辑，备注区含讲解提示。HTML 使用演讲者视图查看备注。投影片通常仅展示当前代码片段，运行请打开 Examples 中的完整文件。

[分章讲义 / Chapter notes](Chapters/README.md)
