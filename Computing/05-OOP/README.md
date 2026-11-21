# C++ 面向对象入门教程

用同一套宠物管理案例逐步演进，从面向过程过渡到类、对象与头文件拆分，再展开封装、继承、多态、抽象，以及析构函数与对象内存模型。

## 目录结构

```text
.
├── README.md
├── 01_basics/                          # 第一篇：类与对象入门
│   ├── tutorial1.md                    # 教程正文
│   ├── proc.cpp                        # 面向过程对照版
│   ├── Pet.hpp                         # Pet 类声明（头文件）
│   ├── Pet.cpp                         # Pet 类实现（源文件）
│   ├── main.cpp                        # 面向对象入门版主程序
│   └── exercise/
│       └── answer_subject.cpp          # 练习参考实现（Subject 类）
└── 02_four_pillars/                    # 第二篇：四大特性、析构函数与内存模型
    ├── tutorial2.md                    # 教程正文
    ├── pet.hpp                         # Pet 及 Cat/Dog/Rabbit 声明
    ├── pet.cpp                         # Pet 及 Cat/Dog/Rabbit 实现
    ├── main.cpp                        # 四大特性综合示例入口
    └── exercise/
        └── answer_course.cpp           # 练习 2 参考实现（多态 Course 体系）
```

## 快速阅读

1. [第一篇：C++ 面向对象入门（一）](01_basics/tutorial1.md)
2. [第二篇：C++ 面向对象入门（二）](02_four_pillars/tutorial2.md)

## 编译与运行

需要支持 C++17 及以上的编译器（如 GCC / MinGW `g++`）：

```bash
# 第一篇示例与练习
g++ -std=c++17 -Wall -Wextra -o proc 01_basics/proc.cpp && ./proc
g++ -std=c++17 -Wall -Wextra -o oop1 01_basics/main.cpp 01_basics/Pet.cpp && ./oop1
g++ -std=c++17 -Wall -Wextra -o answer_subject 01_basics/exercise/answer_subject.cpp && ./answer_subject

# 第二篇示例与练习
g++ -std=c++17 -Wall -Wextra -o oop2 02_four_pillars/main.cpp 02_four_pillars/pet.cpp && ./oop2
g++ -std=c++17 -Wall -Wextra -o answer_course 02_four_pillars/exercise/answer_course.cpp && ./answer_course
```
