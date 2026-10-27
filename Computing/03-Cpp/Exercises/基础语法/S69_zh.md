# S69 二维坐标更新

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入由 UDLR 组成的单词，从 (0,0) 出发，U 增 y，R 增 x，输出终点。

## 样例输入

```text
UURDLR
```

## 样例输出

```text
1 1
```

## 逐步推导

每个字符只改变一个坐标的一步量，按输入顺序累计。

## 关键规则与边界

先明确坐标约定，屏幕坐标常用 y 向下，与本题不同。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string commands;
    std::cin >> commands;
    int x = 0, y = 0;
    for (char c : commands) {
        if (c == 'U')
            ++y;
        else if (c == 'D')
            --y;
        else if (c == 'L')
            --x;
        else if (c == 'R')
            ++x;
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
