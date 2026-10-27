# O21 组合两个电机

Lesson 2 · Chapter 09 · 原课程整合与工程拓展

## 题目

Chassis 包含左右两个 Motor，每个 set 接受速度，drive(2,3) 后输出左右速度。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2 3
```

## 逐步推导

两个部件分别存储左右状态，由 Chassis 的统一入口协调。

## 关键规则与边界

Chassis 拥有 Motor，描述 has-a 关系，成员生命周期由外层对象管理。

## 完整单文件参考程序

```cpp
#include <iostream>

struct Motor {
    int speed = 0;
    void set(int v) { speed = v; }
};
class Chassis {
    Motor left_, right_;

  public:
    void drive(int l, int r) {
        left_.set(l);
        right_.set(r);
    }
    void print() const { std::cout << left_.speed << ' ' << right_.speed << '\n'; }
};

int main() {
    Chassis c;
    c.drive(2, 3);
    c.print();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
