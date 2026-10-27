# O33 对象切片

Lesson 2 · Chapter 09 · 原课程整合与工程拓展

## 题目

Base::kind 返回 BASE，Derived 返回 DERIVED。Derived d 复制到 Base value=d 后分别输出 value 与基类引用的 kind。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
BASE DERIVED
```

## 逐步推导

一次创建切片副本，一次建立引用；分别调用以对照静态存储对象与原对象。

## 关键规则与边界

按值复制到基类对象会切掉派生部分，引用保留原对象身份。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;
    virtual std::string kind() const { return "BASE"; }
};
struct Derived : Base {
    std::string kind() const override { return "DERIVED"; }
};

int main() {
    Derived d;
    Base value = d;
    const Base &ref = d;
    std::cout << value.kind() << ' ' << ref.kind() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
