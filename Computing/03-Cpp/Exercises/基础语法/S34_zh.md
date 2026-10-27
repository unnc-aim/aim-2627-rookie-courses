# S34 数组最大值

Lesson 1 · Chapter 06 · 数组、std::array 与范围遍历

## 题目

输入 n≥1 个 [-1000,1000] 整数，输出最大值。n≤1000。

## 样例输入

```text
3 -9 -2 -7
```

## 样例输出

```text
-2
```

## 逐步推导

先读完整数组，以首元素作当前最大值，再逐个比较替换。

## 关键规则与边界

以首元素初始化最大值，不能默认从 0 开始。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    int best = a[0];
    for (int x : a)
        best = std::max(best, x);
    std::cout << best << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
