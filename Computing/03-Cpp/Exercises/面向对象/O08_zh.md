# O08 委托构造函数

Lesson 2 · Chapter 05 · Band 的构造与初始化

## 题目

Timer() 默认 100ms，Timer(int) 接受正值，非正值变为 1。创建默认对象和 Timer(0)，输出各间隔。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
100 1
```

## 逐步推导

默认构造委托给参数构造，非法间隔修正逻辑只写一次。

## 关键规则与边界

委托构造复用同类的另一构造函数，减少初始化规则重复。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

class Timer {
    int interval_;

  public:
    Timer() : Timer(100) {}
    explicit Timer(int ms) : interval_(std::max(1, ms)) {}
    int interval() const { return interval_; }
};

int main() {
    Timer a;
    Timer b(0);
    std::cout << a.interval() << ' ' << b.interval() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
