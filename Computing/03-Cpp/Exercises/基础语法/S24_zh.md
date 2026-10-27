# S24 安全规则优先级

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入 stop、hp、enemy，按 STOP、DEAD、TRACK、PATROL 的顺序选首个适用动作。stop/enemy 为 0 或 1。

## 样例输入

```text
1 0 1
```

## 样例输出

```text
STOP
```

## 逐步推导

即使急停、死亡、敌人同时出现，也只输出 STOP；因此不能使用互相独立的 if。

## 关键规则与边界

同时命中多个条件时按题目优先级执行，不能用多个独立 if。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int stop = 0, hp = 0, enemy = 0;
    std::cin >> stop >> hp >> enemy;
    if (stop)
        std::cout << "STOP\n";
    else if (hp <= 0)
        std::cout << "DEAD\n";
    else if (enemy)
        std::cout << "TRACK\n";
    else
        std::cout << "PATROL\n";
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
