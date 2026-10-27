# S32 连续命中计数

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入 n 个 0/1，输出最长连续 1 的长度，n∈[0,1000]。

## 样例输入

```text
7 1 1 0 1 1 1 0
```

## 样例输出

```text
3
```

## 逐步推导

读到 1 就延长当前段，读到 0 就归零，每步都更新历史最大段。

## 关键规则与边界

run 是以当前元素结尾的连续长度，best 是历史最优。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int n = 0, value = 0, run = 0, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        run = value == 1 ? run + 1 : 0;
        best = std::max(best, run);
    }
    std::cout << best << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
