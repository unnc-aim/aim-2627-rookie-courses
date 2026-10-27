# O02 两个对象的状态

Lesson 2 · Chapter 04 · 从 struct 到 Band 类

## 题目

创建两个 Counter，只给第一个调用两次 tick，输出两个计数。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2 0
```

## 逐步推导

两个对象分别拥有 `count_`，两次 tick 都发送给 a，因此 b 保持初值。

## 关键规则与边界

普通非 static 数据成员属于各自对象。

## 完整单文件参考程序

```cpp
#include <iostream>

class Counter {
    int count_ = 0;

  public:
    void tick() { ++count_; }
    int value() const { return count_; }
};

int main() {
    Counter a, b;
    a.tick();
    a.tick();
    std::cout << a.value() << ' ' << b.value() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
