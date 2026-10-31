# O34 虚析构函数

第 2 课 · 2.8 · 动态对象、独占所有权与异常清理

## 题目

用 `unique_ptr<Base>` 拥有 Derived，派生析构输出 D、基类析构输出 B。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
D
B
```

## 逐步推导

作用域结束触发拥有指针清理，先派生析构再基类析构。

## 关键规则与边界

通过基类指针管理派生对象生命周期时，基类析构需要 virtual。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <memory>

struct Base {
    virtual ~Base() { std::cout << "B\n"; }
};
struct Derived : Base {
    ~Derived() override { std::cout << "D\n"; }
};

int main() {
    std::unique_ptr<Base> p = std::make_unique<Derived>();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
