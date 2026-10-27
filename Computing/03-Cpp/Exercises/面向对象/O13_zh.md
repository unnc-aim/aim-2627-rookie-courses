# O13 链式调用返回引用

Lesson 2 · Chapter 06 · 实例、方法与乐队集合

## 题目

Config 的 set_speed 与 set_id 返回 Config&，链式设置 3、7 后输出 id:speed。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
7:3
```

## 逐步推导

每次 setter 都返回当前对象引用，第二次调用不落在临时副本上。

## 关键规则与边界

返回 `*this` 的引用保持同一对象，返回值副本会改变后续调用作用的对象。

## 完整单文件参考程序

```cpp
#include <iostream>

class Config {
    int speed_ = 0, id_ = 0;

  public:
    Config &set_speed(int v) {
        speed_ = v;
        return *this;
    }
    Config &set_id(int id) {
        id_ = id;
        return *this;
    }
    void print() const { std::cout << id_ << ':' << speed_ << '\n'; }
};

int main() {
    Config c;
    c.set_speed(3).set_id(7).print();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
