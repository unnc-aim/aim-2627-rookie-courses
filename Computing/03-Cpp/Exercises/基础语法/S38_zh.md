# S38 相邻差分

Lesson 1 · Chapter 06 · 数组、std::array 与范围遍历

## 题目

输入 n≥1 个整数，逐行输出后一项减前一项。n≤1000，元素绝对值≤1000。

## 样例输入

```text
3 2 5 3
```

## 样例输出

```text
3
-2
```

## 逐步推导

第 i 个差分使用 a[i]-a[i-1]，因此循环从 1 而不是 0 开始。

## 关键规则与边界

从下标 1 开始，n=1 时没有输出项。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    for (int i = 1; i < n; ++i)
        std::cout << a[i] - a[i - 1] << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
