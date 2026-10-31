# O06 成员初始化列表

第 2 课 · 2.2 · 构造对象时，就把它准备好

## 题目

Battery 构造函数接收 capacity 和 initial，容量至少 1，电量夹到 [0,capacity]，构造 (10,20) 输出电量。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
10
```

## 逐步推导

先建立规范化容量，再用该容量限制电量；后一个初始化依赖前一个成员。

## 关键规则与边界

成员按声明顺序初始化，列表顺序不会改变实际顺序。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

class Battery {
    int capacity_;
    int charge_;

  public:
    Battery(int capacity, int initial)
        : capacity_(std::max(1, capacity)),
          charge_(std::clamp(initial, 0, capacity_)) {}
    int charge() const { return charge_; }
};

int main() {
    Battery b(10, 20);
    std::cout << b.charge() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
