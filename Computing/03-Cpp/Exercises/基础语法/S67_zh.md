# S67 枚举方向

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

用 enum class 表示四方向 UP=0、RIGHT=1、DOWN=2、LEFT=3，输入 0..3，右转后输出新编号。

## 样例输入

```text
3
```

## 样例输出

```text
0
```

## 逐步推导

把编号加一再对四取余，最后显式转为整数输出。

## 关键规则与边界

enum class 不会隐式转 int。转换本身不验证输入范围，题目已保证范围。

## 完整单文件参考程序

```cpp
#include <iostream>

enum class Facing { Up, Right, Down, Left };

int main() {
    int raw = 0;
    std::cin >> raw;
    Facing facing = static_cast<Facing>(raw);
    facing = static_cast<Facing>((static_cast<int>(facing) + 1) % 4);
    std::cout << static_cast<int>(facing) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
