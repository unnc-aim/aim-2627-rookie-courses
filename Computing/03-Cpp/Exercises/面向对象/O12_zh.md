# O12 this 与同名参数

Lesson 2 · Chapter 06 · 实例、方法与乐队集合

## 题目

Pose 的 set_x(int x) 用 this->x=x 区分同名变量，设置 5 并输出。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
5
```

## 逐步推导

右边 x 取形参，左边 this->x 选当前对象的数据成员。

## 关键规则与边界

this 指向当前对象。也可采用 `x_` 成员命名避免遮蔽。

## 完整单文件参考程序

```cpp
#include <iostream>

class Pose {
    int x = 0;

  public:
    void set_x(int x) { this->x = x; }
    int get_x() const { return x; }
};

int main() {
    Pose p;
    p.set_x(5);
    std::cout << p.get_x() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
