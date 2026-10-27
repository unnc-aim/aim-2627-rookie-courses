# S22 三值中位数

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入三个 [-1000,1000] 整数，输出中位数，允许重复，不排序。

## 样例输入

```text
9 4 4
```

## 样例输出

```text
4
```

## 逐步推导

先求最小与最大值，再从总和中各减一次；重复值也按出现次数处理。

## 关键规则与边界

重复值仍成立。推广到大范围时注意求和类型。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    int lo = std::min(a, std::min(b, c));
    int hi = std::max(a, std::max(b, c));
    std::cout << a + b + c - lo - hi << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
