# C++ Lesson-2: 函数与面向对象

## 课程信息

- **课时**：主课 3 小时，含演示、练习、讨论与 10 分钟休息；拓展另计
- **难度**：基础进阶
- **前置要求**：完成 [Lesson-1](../Lesson-1/README.md)，了解 Python 函数和类
- **语言标准**：C++17

## 学习目标

完成本节课后，学员将能够：

1. 解释参数、局部变量与返回值的关系
2. 说明改指针本身与改指针所指对象的区别
3. 解释值传递与地址传递的交换实验
4. 使用构造函数和公开方法管理私有状态
5. 创建对象集合并按引用遍历
6. 解释基类构造、protected 与 this
7. 运行 Band 综合示例并读懂继承链

## 本课主线

沿用现有讲义与原课程序的演示顺序。先预测程序行为，再运行、分析状态变化并检查边界。

| 顺序 | 现有章节 | 原课对象 |
| --- | --- | --- |
| 1 | 函数：输入、计算与返回 | `test_add` |
| 2 | 引用、地址与指针 | `cite_pointer` |
| 3 | 用交换实验理解参数传递 | `swap1、swap2` |
| 4 | 从 struct 到 Band 类 | `Band、访问控制` |
| 5 | Band 的构造与初始化 | `构造函数、初始化列表` |
| 6 | 实例、方法与乐队集合 | `class_band、std::vector<Band>` |
| 7 | MofoBand：继承与基类构造 | `MofoBand` |
| 8 | protected、this 与第二层派生 | `MofoBand_New` |
| 9 | 原课程整合与工程拓展 | `综合程序、虚函数与所有权` |

## 课程大纲

### 1. 函数：输入、计算与返回

参数初始化、局部变量、调用与返回值；区分 cout 和 return。

### 2. 引用、地址与指针

用 band1、live1、anime1 理解别名、取地址、空指针与解引用。

### 3. 用交换实验理解参数传递

区分参数副本与调用者对象；指针参数自身仍按值传递。

### 4. 从 struct 到 Band 类

保留乐队成员模型，解释默认访问权限、private、public 与封装。

### 5. Band 的构造与初始化

先解释原程序的函数体赋值，再认识初始化列表与成员初始化次序。

### 6. 实例、方法与乐队集合

创建对象、调用接口、存放多个对象；比较按值和按引用遍历。

### 7. MofoBand：继承与基类构造

基类子对象、public 继承、基类构造调用与私有成员访问限制。

### 8. protected、this 与第二层派生

在派生类中修改声优字段，理解 protected、this 与 const string&。

### 9. 原课程整合与工程拓展

先运行整合流程，再阅读虚函数、对象切片与资源所有权拓展。

## 课堂材料

- **完整讲义**：[中文](./Lecture.md) · [English](./Lecture_en.md) · [中文 PDF](./Lecture.pdf) · [English PDF](./Lecture_en.pdf)
- **课件**：[中文 PDF](./Slides.pdf) · [English PDF](./Slides_en.pdf) · [中文 PPTX](./Slides.pptx) · [English PPTX](./Slides_en.pptx)
- **Marp 源稿**：[中文](./Slides.md) · [English](./Slides_en.md)
- **完整程序**：[正文实验与例题索引](./Examples/README.md) · [综合演示 Demo.cpp](./Demo.cpp)

## 实践项目

运行现有 Band 综合程序，观察构造、成员调用、对象集合、继承和 protected 状态修改；本课综合演示无需输入。

## 课堂练习

按讲义章节选择配套例题，先预测输出，再运行并解释差异。[双语例题索引](../Exercises/README.md) 按实际课次和章节列出全部题目；S 系列中的函数、引用和指针题按原顺序安排到第二课。

## 课后作业

完成 [Assessment-02 学生模板](../Assessment-02/README.md)，要求与评分以 [中文题面](../Assessment-02/PROBLEM.md) / [English statement](../Assessment-02/PROBLEM_en.md) 为准。引用、指针、虚函数与所有权相关题目在第二课对应章节后完成。

## 学习检查点

- [ ] 能解释参数、局部变量与返回值的关系
- [ ] 能说明改指针本身与改指针所指对象的区别
- [ ] 能解释值传递与地址传递的交换实验
- [ ] 能使用构造函数和公开方法管理私有状态
- [ ] 能创建对象集合并按引用遍历
- [ ] 能解释基类构造、protected 与 this
- [ ] 能运行 Band 综合示例并读懂继承链

## 扩展阅读

- [C++ 语言参考](https://en.cppreference.com/w/cpp/language)
- [C++ 标准容器](https://en.cppreference.com/w/cpp/container)

[返回 C++ 模块](../README.md) · [下一模块：ROS2](../../04-ROS2/README.md)

## 课堂放映与逐页提示

本课课件独立编排为 63 页，主课时间表按 180 分钟安排。采用讲解、预测、运行、逐步推导、练习与讲评交替的节奏。完整讲义用于查阅，整套例题用于加练。第二课末尾约 14 分钟为可选拓展。

[中文放映](Slides.html) · [English slideshow](Slides_en.html) · [中文逐页授课提示](TeachingGuide.md) · [English teaching guide](TeachingGuide_en.md)

PPTX 中的文字和代码可编辑，备注区含讲解提示。HTML 使用演讲者视图查看备注。投影片通常仅展示当前代码片段，运行请打开 Examples 中的完整文件。

[分章讲义 / Chapter notes](Chapters/README.md)
