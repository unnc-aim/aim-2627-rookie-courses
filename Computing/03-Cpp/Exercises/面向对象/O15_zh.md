# O15 静态成员函数

Lesson 2 · Chapter 06 · 实例、方法与乐队集合

## 题目

Limits::valid 不依赖对象，只判断速度是否在 [-3,3]，分别检查 3、4。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 0
```

## 逐步推导

通过类名调用，只依据参数判断，不创建无意义的实例。

## 关键规则与边界

static 成员函数没有 this，不能直接读取某个对象的普通成员。

## 完整单文件参考程序

```cpp
#include <iostream>

class Limits {
  public:
    static bool valid(int speed) { return speed >= -3 && speed <= 3; }
};

int main() {
    std::cout << Limits::valid(3) << ' ' << Limits::valid(4) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
