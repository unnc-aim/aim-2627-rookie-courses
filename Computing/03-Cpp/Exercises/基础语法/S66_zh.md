# S66 最近目标

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入 n≥1 个 id、x、y，取距离原点平方最小者，相同取 id 小者。坐标绝对值≤1000，n≤1000。

## 样例输入

```text
3 9 3 4 2 -3 -4 7 6 0
```

## 样例输出

```text
2
```

## 逐步推导

先比较平方距离，距离相等再比较 id；保存整条最佳记录。

## 关键规则与边界

平方距离足够比较大小，无需开根号；平局规则不能依赖输入顺序。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <limits>

struct Target {
    int id = 0;
    int x = 0;
    int y = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    Target best = {};
    long long best_d = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
        Target t = {};
        std::cin >> t.id >> t.x >> t.y;
        long long d = 1LL * t.x * t.x + 1LL * t.y * t.y;
        if (d < best_d || (d == best_d && t.id < best.id)) {
            best = t;
            best_d = d;
        }
    }
    std::cout << best.id << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
