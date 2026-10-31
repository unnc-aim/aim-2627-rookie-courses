# O31 virtual 动态派发

第 2 课 · 2.7 · 多态：用同一个接口操作不同对象

## 题目

Base::kind 虚函数返回 BASE，Derived override 返回 SENTRY，通过 const Base& 调用输出 SENTRY。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
SENTRY
```

## 逐步推导

引用不创建基类副本，调用根据原对象动态类型选择派生实现。

## 关键规则与边界

通过基类引用或指针调用虚函数时，根据对象的动态类型派发。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;
    virtual std::string kind() const { return "BASE"; }
};
struct Derived : Base {
    std::string kind() const override { return "SENTRY"; }
};

int main() {
    Derived d;
    const Base &ref = d;
    std::cout << ref.kind() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
