# S57 值传递不能交换实参

Lesson 2 · Chapter 03 · 用交换实验理解参数传递

## 题目

swap_value 中交换副本，输入 a、b 后调用并输出原实参。

## 样例输入

```text
10 20
```

## 样例输出

```text
10 20
```

## 逐步推导

分别追踪 main 与函数里的两组整数，不用函数内输出冒充外部状态。

## 关键规则与边界

函数没有编译错误，但修改的是形参副本。

## 完整单文件参考程序

```cpp
#include <iostream>

void swap_value(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_value(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
