# O30 同名隐藏与限定调用

第 2 课 · 2.6 · 继承：派生对象中的基类部分

## 题目

Base::name 返回 BASE，Derived 定义同名非虚 name 返回 DERIVED，分别调用 d.name 与 d.Base::name。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
DERIVED BASE
```

## 逐步推导

默认选择派生同名方法，显式 Base:: 再选择基类实现。

## 关键规则与边界

同名非虚成员发生隐藏，不能把它与 virtual 动态派发混为一谈。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

struct Base {
    std::string name() const { return "BASE"; }
};
struct Derived : Base {
    std::string name() const { return "DERIVED"; }
};

int main() {
    Derived d;
    std::cout << d.name() << ' ' << d.Base::name() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
