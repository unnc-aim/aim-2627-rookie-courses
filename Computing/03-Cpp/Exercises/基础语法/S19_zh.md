# S19 开火门控

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入 hp、heat、enemy（0 或 1），hp>0、heat<100 且 enemy=1 才输出 FIRE，否则 WAIT。

## 样例输入

```text
100 100 1
```

## 样例输出

```text
WAIT
```

## 逐步推导

把三个条件先写成一个 bool，特别核对 heat=100 必须等待。

## 关键规则与边界

&& 两端为逻辑条件，并按从左到右短路求值。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int hp = 0, heat = 0, enemy = 0;
    std::cin >> hp >> heat >> enemy;
    bool fire = hp > 0 && heat < 100 && enemy == 1;
    std::cout << (fire ? "FIRE" : "WAIT") << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
