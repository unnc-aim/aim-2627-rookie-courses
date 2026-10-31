# O29 构造与析构的层次

第 2 课 · 2.6 · 继承：派生对象中的基类部分

## 题目

Base 与 Derived 构造、析构分别输出 +B、+D、-D、-B，创建一个 Derived 验证次序。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
+B
+D
-D
-B
```

## 逐步推导

按先基类后派生构造、逆序析构排出四行，不混入动态分配。

## 关键规则与边界

先构造基类，再构造派生部分；销毁时顺序相反。此例不通过基类指针删除。

## 完整单文件参考程序

```cpp
#include <iostream>

struct Base {
    Base() { std::cout << "+B\n"; }
    ~Base() { std::cout << "-B\n"; }
};
struct Derived : Base {
    Derived() { std::cout << "+D\n"; }
    ~Derived() { std::cout << "-D\n"; }
};

int main() {
    Derived d;
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
