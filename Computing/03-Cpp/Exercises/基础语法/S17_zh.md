# S17 血量三档

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入血量 [0,100]，0 输出 DEAD，1..30 输出 LOW，其余 OK。

## 样例输入

```text
30
```

## 样例输出

```text
LOW
```

## 逐步推导

先处理零，再判断不超过 30；剩余区间无需重复写 hp>30。

## 关键规则与边界

按互斥区间从特殊到一般判断，边界 0 与 30 都要测。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int hp = 0;
    std::cin >> hp;
    if (hp == 0)
        std::cout << "DEAD\n";
    else if (hp <= 30)
        std::cout << "LOW\n";
    else
        std::cout << "OK\n";
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
