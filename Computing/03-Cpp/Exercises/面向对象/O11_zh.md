# O11 const 成员函数

第 2 课 · 2.3 · 怎样使用和传递对象：const、this、复制与引用

## 题目

Counter 提供 value() const，const Counter(8) 能读取计数，不能调用 tick。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
8
```

## 逐步推导

只读对象只能走只读接口，修改方法作为单独编译错误实验。

## 关键规则与边界

成员函数末尾的 const 约束本次调用不能修改普通成员。

## 完整单文件参考程序

```cpp
#include <iostream>

class Counter {
    int value_;

  public:
    explicit Counter(int n) : value_(n) {}
    int value() const { return value_; }
    void tick() { ++value_; }
};

int main() {
    const Counter c(8);
    std::cout << c.value() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
