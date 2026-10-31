# O27 基类构造委托

第 2 课 · 2.6 · 继承：派生对象中的基类部分

## 题目

Robot 必须给定 id 构造，Sentry 接收 id 并初始化基类，构造 9 输出 9。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
9
```

## 逐步推导

冒号后把编号传给 Robot，不能在派生构造体里补造基类。

## 关键规则与边界

派生类构造函数先初始化基类子对象，再初始化自身成员。

## 完整单文件参考程序

```cpp
#include <iostream>

class Robot {
    int id_;

  public:
    explicit Robot(int id) : id_(id) {}
    int id() const { return id_; }
};
class Sentry : public Robot {
  public:
    explicit Sentry(int id) : Robot(id) {}
};

int main() {
    Sentry s(9);
    std::cout << s.id() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
