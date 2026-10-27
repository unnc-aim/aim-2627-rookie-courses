# S77 网格碰撞

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入宽 w、高 h 与 UDLR 指令串，从 (0,0) 出发，U 增 y。越界动作原地不动且碰撞加一。w,h≥1，输出 x、y、碰撞数。

## 样例输入

```text
2 2 RRUU
```

## 样例输出

```text
1 1 2
```

## 逐步推导

候选坐标与当前位置分开，撞边界只增加碰撞，不先移动再修补。

## 关键规则与边界

先计算候选位置，再验证，最后提交状态。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    int w = 0, h = 0, x = 0, y = 0, collisions = 0;
    std::string commands;
    std::cin >> w >> h >> commands;
    for (char c : commands) {
        int nx = x + (c == 'R') - (c == 'L');
        int ny = y + (c == 'U') - (c == 'D');
        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            ++collisions;
        else {
            x = nx;
            y = ny;
        }
    }
    std::cout << x << ' ' << y << ' ' << collisions << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
