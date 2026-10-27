# S40 循环右移

Lesson 1 · Chapter 06 · 数组、std::array 与范围遍历

## 题目

输入 n≥1、k≥0 与 n 个整数，右移 k 位，每行输出一个元素。n≤1000，k≤10^9。

## 样例输入

```text
3 4 1 2 3
```

## 样例输出

```text
3
1
2
```

## 逐步推导

把原索引 i 的元素送到 (i+k)%n，先对 k 取余以消除完整周期。

## 关键规则与边界

先对 n 取余，使用独立结果数组避免覆盖尚未读取的数据。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int &x : a)
        std::cin >> x;
    k %= n;
    for (int i = 0; i < n; ++i)
        b[(i + k) % n] = a[i];
    for (int x : b)
        std::cout << x << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
