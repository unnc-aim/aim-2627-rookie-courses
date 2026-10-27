# S68 二维数组行和

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

读取 2×3 矩阵，逐行输出该行元素和。元素绝对值≤1000。

## 样例输入

```text
1 2 3 4 5 6
```

## 样例输出

```text
6
15
```

## 逐步推导

外层每次建立一个新的行和，内层遍历该行元素，不把两行累加到同一结果。

## 关键规则与边界

外层行，内层列。固定矩阵可用嵌套 array。

## 完整单文件参考程序

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<std::array<int, 3>, 2> grid = {};
    for (std::array<int, 3> & row : grid)
        for (int &x : row)
            std::cin >> x;
    for (const std::array<int, 3> & row : grid) {
        int sum = 0;
        for (int x : row)
            sum += x;
        std::cout << sum << '\n';
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
