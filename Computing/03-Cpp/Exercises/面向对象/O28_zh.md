# O28 protected 的可见性

第 2 课 · 2.6 · 继承：派生对象中的基类部分

## 题目

Base 的 hp=10 为 protected，Derived::damage 减 3，通过 public getter 输出 7。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
7
```

## 逐步推导

派生方法通过允许的访问路径减血，main 使用公开读取接口。

## 关键规则与边界

当前类与派生类成员函数可访问 protected，普通外部调用者不可直接访问。

## 完整单文件参考程序

```cpp
#include <iostream>

class Base {
  protected:
    int hp_ = 10;

  public:
    int hp() const { return hp_; }
};
class Derived : public Base {
  public:
    void damage() { hp_ -= 3; }
};

int main() {
    Derived d;
    d.damage();
    std::cout << d.hp() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
