# S26 哨兵值输入

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

不断读取整数，遇到 -1 或 EOF 停止，输出之前的和，-1 不参与。

## 样例输入

```text
1 2 3 -1 99
```

## 样例输出

```text
6
```

## 逐步推导

短路条件先读取，再检查是否为 -1；只有两个条件都满足时才累加。

## 关键规则与边界

读取成功和哨兵条件同时控制循环。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x && x != -1)
        total += x;
    std::cout << total << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
