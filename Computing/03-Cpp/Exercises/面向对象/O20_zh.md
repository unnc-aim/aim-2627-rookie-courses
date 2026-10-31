# O20 静态活对象计数

第 2 课 · 2.5 · 对象何时结束，资源由谁清理？

## 题目

Tracker 的默认构造和复制构造使 live+1，析构 live-1，作用域外最终计数为 0。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2
0
```

## 逐步推导

默认构造与复制构造各加一，两个析构各减一，核对最终回到零。

## 关键规则与边界

复制构造也创建新对象，统计时不能遗漏。此例只演示计数，不包含资源所有权。

## 完整单文件参考程序

```cpp
#include <iostream>

class Tracker {
  public:
    inline static int live = 0;
    Tracker() { ++live; }
    Tracker(const Tracker &) { ++live; }
    ~Tracker() { --live; }
};

int main() {
    {
        Tracker a;
        Tracker b = a;
        std::cout << Tracker::live << '\n';
    }
    std::cout << Tracker::live << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
