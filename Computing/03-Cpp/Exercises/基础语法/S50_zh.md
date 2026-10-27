# S50 声明与定义

Lesson 2 · Chapter 01 · 函数：输入、计算与返回

## 题目

在 main 前声明 square，定义也放在程序中，输入 [-1000,1000] 的 x，输出平方。

## 样例输入

```text
5
```

## 样例输出

```text
25
```

## 逐步推导

核对声明和定义的名字、参数、返回类型一致，再在 main 中调用。

## 关键规则与边界

编译器在调用点需要声明，链接器最终需要匹配的定义。

## 完整单文件参考程序

```cpp
#include <iostream>

int square(int x);
int square(int x) { return x * x; }

int main() {
    int x = 0;
    std::cin >> x;
    std::cout << square(x) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
