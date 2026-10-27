# S31 矩形输出

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入行数 r 和列数 c，均在 [1,10]，输出 r 行 c 个 #。

## 样例输入

```text
2 3
```

## 样例输出

```text
###
###
```

## 逐步推导

内层每次打印一个 #，内层结束才换行；外层决定共打印几行。

## 关键规则与边界

内循环负责一行，换行留在内循环外。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int r = 0, c = 0;
    std::cin >> r >> c;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x)
            std::cout << '#';
        std::cout << '\n';
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
