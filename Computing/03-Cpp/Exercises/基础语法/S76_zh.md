# S76 热量仿真

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入 n、初始热量 h、冷却 c、每发热量 d，之后 n 个 0/1。每步先冷却至不低于 0，指令为 1 且 h+d≤100 才射击。输出射击数与最终热量。参数非负≤100，n≤1000。

## 样例输入

```text
3 90 10 20 1 1 1
```

## 样例输出

```text
2 100
```

## 逐步推导

每步先冷却，再验证本次射击；样例末态为 100，不能把中途的 90 当末态。

## 关键规则与边界

状态更新的先后次序属于规格，先射击再冷却会改变边界结果。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

int main() {
    int n = 0, h = 0, cool = 0, delta = 0, shots = 0;
    std::cin >> n >> h >> cool >> delta;
    for (int i = 0; i < n; ++i) {
        int fire = 0;
        std::cin >> fire;
        h = std::max(0, h - cool);
        if (fire && h + delta <= 100) {
            h += delta;
            ++shots;
        }
    }
    std::cout << shots << ' ' << h << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
